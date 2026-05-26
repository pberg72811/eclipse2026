
import numpy as np 
import matplotlib.pyplot as plt
from PIL import Image

class SystemParameters:
    def __init__(self,N=2048,
                 R=6.4e-3,phi=0,wavelength=520e-9,f=1e-3,
                 dx_sim=0.1e-6,dy_sim=0.1e-6,pixel_pitch=1.5e-6,t_exp=1,quantum_efficiency=0.767, optics_transmission=1,
                 dark_current=2.5, well_depth=1e5, ndynamic=256):
        
        self.N = N                                      # Samples for HxW of each Optical Point Spread Function
        self.R = R                                      # Radius of Optical Aperture
        self.phi = phi                                  # Phase of Aperture (controls aberrations caused by image)
        self.lambda0 = wavelength                       # wavelength (how long one period of wave is in space)
        self.focal_len = f                              # focal length (where light rays converge in optical system)
        self.dx_sim = dx_sim                            # change in length of image (used to calculate sampling of image)
        self.dy_sim = dy_sim                            # Change in width of image  (used to calculate sampling of image)
        self.p = pixel_pitch                            # sampling pitch (physical size of detector length x width)
        self.t_exp = t_exp                              # exposure time
        self.f_number = self.focal_len / (2 * self.R)   # f_number (light gathering ability of optical system)
        self.eta = quantum_efficiency                   # quantum efficiency (function of wavelength)
        self.tau = optics_transmission                  # optical transmission (function of wavelength)
        self.dark_current = dark_current                # dark current (signal of optical system when image is completely black)
        self.well_depth = well_depth                    # well depth (maximum amount of electrons one detector can hold before saturating)
        self.ndynamic = ndynamic                        # dynamic range of image based off 2 ^ power

class Radiometry:
    """Handles L_scene(x, y, λ)."""
    def __init__(self, params):
        self.p = params
        self.scene = None           # spectral radiance map
        self.X = None
        self.Y = None

    def get_radiance(self,x0,y0,sigma):
        # 2D Gaussian Definition
        x = np.linspace(-5, 5, self.p.N)
        y = np.linspace(-5, 5, self.p.N)
        self.X, self.Y = np.meshgrid(x,y)
        self.scene = np.exp(-((self.X - x0) ** 2 + (self.Y - y0) **2) / (2 * sigma ** 2))
        return self.scene
    
    def graph_radiance(self):
        fig = plt.figure()
        ax = plt.axes(projection='3d')
        ax.plot_surface(self.X, self.Y, self.scene, cmap='viridis')
        plt.show()

    def USAF_Target(self):
        img = Image.open('USAF_Target.jpg').convert("L")
        img = np.array(img)
        return img

class OpticalSystem:
    """Handles optical PSF and image formation (convolution)."""
    def __init__(self, params):
        self.p = params
        self.psf = None            # optical PSF
        self.otf = None            # optical transfer function
        self.aperture = None
        self.U = None
        self.V = None
        self.w = None
        self.du = None
        self.dx = None

    def compute_aperture(self):

        self.w = 4*self.p.R
        self.du = self.w / self.p.N

        u = np.linspace(-self.w/2, self.w/2 - self.du, self.p.N)
        v = np.linspace(-self.w/2, self.w/2 - self.du, self.p.N)
        self.U, self.V = np.meshgrid(u,v)

        r = np.sqrt(self.U **2 + self.V **2)

        amplitude = (r <= self.p.R).astype(float) 

        self.aperture = amplitude * np.exp(-1j*self.p.phi)
        return self.aperture

    def graph_aperture(self):
        # Plot pupil
        plt.pcolormesh(self.U, self.V, np.abs(self.aperture), cmap='viridis')
        plt.gca().set_aspect('equal')
        plt.title('OpticalSystem Aperture')
        plt.show()

    def compute_aperture_psf(self):

        # aperture
        self.aperture = self.compute_aperture()

        # FFT → PSF
        h = np.fft.fftshift(np.fft.fft2(np.fft.ifftshift(self.aperture))) * self.du**2
        self.psf = np.abs(h)**2
        return self.psf

    def graph_psf(self):
        
        # sampling of psf
        self.dx = (self.p.lambda0 * self.p.focal_len) / self.w

        # Image-plane coordinate grid
        x = np.linspace(-self.p.N/2 * self.dx, (self.p.N/2 - 1)*self.dx, self.p.N)
        y = x.copy()
        X, Y = np.meshgrid(x, y)

        # Takes zeros out of plot
        # threshold = 1e-12
        # self.psf = np.ma.masked_where(self.psf < threshold, self.psf)

        plt.pcolormesh(X, Y, self.psf/np.max(self.psf), cmap='viridis')
        plt.title('Aperture PSF')
        
    def form_image(self, L_scene):
        # Eq. (1): L_image = L_scene * PSF_system
        # For now assume PSF_system = PSF_optical

        # point spread function
        self.psf = self.compute_aperture_psf()

        # Dimensions of matrix to avoid time domain aliasing
        row = self.psf.shape[0] + L_scene.shape[0]
        col = self.psf.shape[1] + L_scene.shape[1]

        # optical transfer function
        self.otf = np.fft.fft2(self.psf, (row, col))

        # fft of image 
        image_fft = np.fft.fft2(L_scene, (row, col))

        # image as seen through aperture
        image_apt = np.fft.ifft2(self.otf * image_fft)

        return image_apt
    
class Detector:
    """Models the detector aperture PSF and sampling."""
    def __init__(self, params):
        self.p = params
        self.det_psf = None

    def compute_detector_psf(self):
        # Create 2D rect aperture (Eq. 20).

        # coordinate system of the detector aperture
        x = np.linspace(-2*self.p.p, 2*self.p.p, self.p.N)
        y = np.linspace(-2*self.p.p, 2*self.p.p, self.p.N)
        X, Y = np.meshgrid(x,y)

        # Define 2D rectangle function
        mask = (np.abs(X) <= self.p.p/2) & (np.abs(Y) <= self.p.p/2)  
        rect2D = np.zeros(X.shape)
        rect2D[mask] = 1
        self.det_psf = rect2D
        self.det_psf = self.det_psf / np.sum(self.det_psf)
        return self.det_psf

    def apply_detector_blur(self, L_image):
        
        # detector psf
        self.det_psf = self.compute_detector_psf() 

        # Zero Pad det_psf function
        row = L_image.shape[0] 
        col = L_image.shape[1] 
        # self.det_psf = np.pad(self.det_psf, (row//4 , col//4))

        # fft of rectangle function
        det_otf = np.fft.fft2(self.det_psf, (row, col))

        # fft of L_image
        L_image_fft = np.fft.fft2(L_image, (row, col))

        # image seen by the aperture and then the detector
        image_det = np.abs(np.fft.ifft2(det_otf * L_image_fft))

        return image_det

    def sample(self, blurred_image):

        # Eq. (22)-(23): sampling at pixel pitch p

        samp_pitch_x = int(self.p.p / self.p.dx_sim)
        samp_pitch_y = int(self.p.p / self.p.dy_sim)

        # Use nearest or interpolation-based sampling
        return blurred_image[::samp_pitch_x, ::samp_pitch_y]

    def compute_signal(self, L_image_lambda, wavelength):
        """
        Implements Eq. (27) simplified to one wavelength:
        s_detector = (π d² t_exp / (4 (f/#)²)) * (λ/(hc)) * η * τ * L_image
        """

        d = self.p.p    # assume square pixels for simplicity
        h = 6.626e-34   # Plank's constant
        c = 3e8         # Speed of light
        coeff = (np.pi * d**2 * self.p.t_exp) / (4 * (self.p.f_number**2))
        photon_scale = (wavelength / (h * c))
        s_detector = coeff * photon_scale * self.p.eta * self.p.tau * L_image_lambda
        return s_detector
    
class NoiseModel:
    """Applies sensor noises: photon, quantization, dark noise."""
    def __init__(self, params):
        self.p = params

    def apply_noise(self, s_detector):
        """
        Implements Eq. (29)-(30):
        σ_total = sqrt( s + σ_dark^2 + quantization_noise^2 )
        """
        
        photon_noise = s_detector
        quant_noise = (1/12) * (self.p.well_depth / self.p.ndynamic) **2 *np.ones(s_detector.shape)
        dark_noise = self.p.dark_current * self.p.t_exp * np.ones(s_detector.shape)
        noise_std = np.sqrt(photon_noise + quant_noise + dark_noise)
        sensor_noise = np.random.normal(loc=0, scale=noise_std, size=s_detector.shape)

        return s_detector + sensor_noise

class ImageCapture:
    """Final digital count quantization."""
    def __init__(self, params):
        self.p = params

    def quantize(self, electrons):
        """
        Uses Eq. (28): counts = floor( s_detector / N_well * N_DR )
        """

        electron_limit = np.clip(electrons / self.p.well_depth, 0, 1)

        counts = np.floor(electron_limit * (self.p.ndynamic - 1))

        return counts

class ImagingChain:
    """Connect all elements from Fig. 16."""
    def __init__(self, radiometry, optics, detector, noise, capture):
        self.radiometry = radiometry
        self.optics = optics
        self.detector = detector
        self.noise = noise
        self.capture = capture

    def run(self):
        # Step 1: Radiometry
        # L_scene = self.radiometry.get_radiance(x0=0,y0=0,sigma=1)
        L_scene = self.radiometry.USAF_Target()

        # Step 2: Image formation (optical blur)
        L_image_apt = self.optics.form_image(L_scene)

        # Step 3: Detector blur
        L_image_det = self.detector.apply_detector_blur(L_image_apt)

        # Step 4: Compute detector signal for one wavelength
        s_det = self.detector.compute_signal(L_image_det,
                                             self.radiometry.p.lambda0)

        # Step 5: Sampling
        sampled = self.detector.sample(s_det)

        # Step 6: Noise
        noisy = self.noise.apply_noise(sampled)

        # Step 7: Digitization
        final_counts = self.capture.quantize(noisy)


        plt.subplot(2,4,1)
        plt.imshow(L_scene, cmap='gray')
        plt.title('Scene Radiance')

        plt.subplot(2,4,2)
        self.optics.graph_psf()

        plt.subplot(2,4,3)
        plt.imshow(np.abs(L_image_apt))
        plt.title('Scene through Apt')

        plt.subplot(2,4,4)
        plt.imshow(L_image_det)
        plt.title('Scene through Apt & Det')

        plt.subplot(2,4,5)
        plt.imshow(sampled)
        plt.title('Sampled Image')

        plt.subplot(2,4,6)
        plt.imshow(noisy)
        plt.title('Image w/ Noise')

        plt.subplot(2,4,7)
        plt.imshow(final_counts)
        plt.title('Digitalized Image')
        plt.show()

if __name__ == '__main__':
    
    # Initalize Classes
    params = SystemParameters()
    rad = Radiometry(params=params)
    opt_sys = OpticalSystem(params=params)
    det = Detector(params=params)
    noise = NoiseModel(params=params)
    capture = ImageCapture(params=params)
    chain = ImagingChain(radiometry=rad,optics=opt_sys,detector=det,noise=noise,capture=capture)

    final_counts = chain.run()
    # plt.imshow(final_counts)
    # plt.show()

    # # Test Radiometry Class
    # radiance = rad.get_radiance(x0=0,y0=0,sigma=1)
    # rad_graph = rad.graph_radiance()

    # # Test Optical System Class
    # aperture = opt_sys.compute_aperture()
    # apt_graph = opt_sys.graph_aperture()
    # image = opt_sys.form_image(radiance)
    # plt.imshow(np.abs(image))
    # plt.show()
