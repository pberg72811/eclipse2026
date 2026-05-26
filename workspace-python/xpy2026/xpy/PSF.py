import numpy as np 
import scipy.fft as sfft 
import matplotlib.pyplot as plt 
from scipy.integrate import simpson
from scipy.interpolate import RectBivariateSpline
from scipy.interpolate import interpn
import PIL as pil

#####################################################################
############################# FUNCTIONS #############################
#####################################################################
def ift2(dfx,dfy,G):
    Nx = np.size(G,1) 
    Ny = np.size(G,0) 
    g = sfft.ifftshift(sfft.ifft(sfft.ifftshift( \
        sfft.ifftshift(sfft.ifft(sfft.ifftshift( \
        G,axes=1),axis=1),axes=1),axes=0),axis=0),axes=0)*dfx*dfy*Nx*Ny 
    return g

def ft2(dx,dy,g):
    G = sfft.fftshift(sfft.fft(sfft.fftshift( \
        sfft.fftshift(sfft.fft(sfft.fftshift( \
        g,axes=1),axis=1),axes=1),axes=0),axis=0),axes=0)*dx*dy
    return G

def conv_ft(dx,dy,A,B):
    Nx = np.size(A,1)
    Ny = np.size(A,0)
    Aft = ft2(dx,dy,A)
    Bft = ft2(dx,dy,B)
    dfx = 1/(Nx*dx)
    dfy = 1/(Ny*dy)
    return ift2(dfx,dfy,Aft*Bft)

def circ(x,y,D):
    z = np.zeros(np.shape(x)) 
    z[np.sqrt(x**2+y**2)<=D/2] = 1 
    #z[np.sqrt(x**2+y**2)==D/2] = 1/2 
    return z 

def rect(x,W):
    y = np.zeros(np.shape(x))
    y[np.abs(x)<=W/2] = 1
    return y
#####################################################################
#####################################################################
#####################################################################

wvl_min = 400e-9
wvl_max = 2500e-9
wvl_mean = (wvl_min+wvl_max)/2
wvl = np.array([wvl_min,wvl_mean,wvl_max])
k = 2*np.pi/wvl

# ----- Aperture ----- #
D = 0.25
d = D/4
struts = d/10
# -------------------- #

# ---- Pupil-Plane Grid ----- #
Lpup = 20*D
dpup = struts/4
N = np.ceil(Lpup/dpup).astype('int')
if np.remainder(N,2) != 0:
    N = N + 1
dpup = Lpup/N
xpup,ypup = np.meshgrid(np.arange(-N/2,N/2)*dpup, \
    np.arange(-N/2,N/2)*dpup)
dpsf = wvl/(N*dpup)
NX,NY = np.meshgrid(np.arange(-N/2,N/2),np.arange(-N/2,N/2))
xpsf = np.tensordot(NX,dpsf,axes=0)
ypsf = np.tensordot(NY,dpsf,axes=0)
# --------------------------- #

# Aperture_Mask = circ(xpup,ypup,D)*(circ(xpup,ypup,D)-circ(xpup,ypup,d) \
#     -(rect(xpup-1/2*D/2,D/2)*rect(ypup-d/2+struts/2,struts) \
#     +rect(xpup+d/2-struts/2,struts)*rect(ypup-1/2*D/2,D/2) \
#     +rect(xpup+1/2*D/2,D/2)*rect(ypup+d/2-struts/2,struts) \
#     +rect(xpup-d/2+struts/2,struts)*rect(ypup+1/2*D/2,D/2)))
Aperture_Mask = circ(xpup,ypup,D)
Aperture_Mask[Aperture_Mask < 0] = 0
Aperture_Mask = Aperture_Mask*np.exp(1j*k[1]*0.00000*xpup)    

# ================= Read In USAF Bar Chart ======================== #
dobj = wvl/(10*D)
xobj = np.tensordot(NX,dobj,axes=0)
yobj = np.tensordot(NY,dobj,axes=0)
USAF = np.array(pil.Image.open('USAF_Target.jpg').convert(mode='L'),dtype='float')
if np.remainder(np.shape(USAF)[0],2) != 0:
    USAF = np.delete(USAF,(0),axis=0)
if np.remainder(np.shape(USAF)[1],2) != 0:
    USAF = np.delete(USAF,(0),axis=1)
USAF_pad = np.pad(USAF, \
    pad_width=((int(N/2-np.shape(USAF)[0]/2),),(int(N/2-np.shape(USAF)[1]/2),)))
# ================================================================= #

PSF = np.zeros((N,N,len(wvl)))
for ww in np.arange(len(wvl)):    
    PSFu = np.abs(ft2(dpsf[ww],dpsf[ww],Aperture_Mask))**2
    PSF[:,:,ww] = PSFu/simpson(simpson(PSFu,x=xpsf[0,:,ww],axis=1),x=ypsf[:,0,ww],axis=0)
PSF = PSF/np.max(PSF[:,:,0])    

ind = 1
PSF_spline = RectBivariateSpline(xpsf[0,:,ind],ypsf[:,0,ind],PSF[:,:,ind]) 
PSF_interp = PSF_spline(xobj[0,:,ind],yobj[:,0,ind],grid=True)
Im = np.real(conv_ft(dobj[ind],dobj[ind],PSF_interp,USAF_pad))

dpix = 3.45e-6
Nx = 2464; Ny = 2056
xdet,ydet = np.meshgrid(np.arange(-Nx/2,Nx/2)*dpix,np.arange(-Ny/2,Ny/2)*dpix)
Iim = interpn((yobj[:,0,ind],xobj[0,:,ind]),Im,(np.ravel(ydet),np.ravel(xdet)),\
    method='nearest',bounds_error=False,fill_value=0)
Iim = np.reshape(Iim,[Ny,Nx])    


plt.rcParams['text.usetex'] = True
plt.rcParams['font.family'] = 'serif'
plt.rcParams['font.serif'] = 'Computer Modern'
plt.rcParams['text.latex.preamble'] = r'\usepackage{amsmath}'
plt.rcParams['text.latex.preamble'] = r'\usepackage{amsfonts}'

fig,axs = plt.subplots(nrows=1,ncols=2,layout='compressed')
p=axs[0].imshow(np.abs(Aperture_Mask),cmap='viridis', \
    extent=[xpup[0,0],xpup[0,-1],ypup[0,0],ypup[-1,0]])
axs[0].set_xlabel(r'$x$ (m)',fontsize=10)
axs[0].set_ylabel(r'$y$ (m)',fontsize=10)
#cb = plt.colorbar(p,ax=axs[0])
#cb.ax.tick_params(labelsize=10)
axs[0].tick_params(axis='both',labelsize=10)
axs[0].set_xlim([-D,D])
axs[0].set_ylim([-D,D])

p=axs[1].imshow(PSF[:,:,ind],cmap='viridis', \
    extent=[xpsf[0,0,ind]*1e3,xpsf[0,-1,ind]*1e3,ypsf[0,0,ind]*1e3,ypsf[-1,0,ind]*1e3])
axs[1].set_xlabel(r'$x/f$ (mrad)',fontsize=10)
axs[1].set_ylabel(r'$y/f$ (mrad)',fontsize=10)
axs[1].set_xlim([-10*wvl[ind]/D*1e3,10*wvl[ind]/D*1e3])
axs[1].set_ylim([-10*wvl[ind]/D*1e3,10*wvl[ind]/D*1e3])
axs[1].tick_params(axis='both',labelsize=10)
#p.set_clim([0,np.max(PSF[:,:,ind])/100])

fig,axs = plt.subplots(nrows=1,ncols=3,layout='compressed')
axs[0].imshow(USAF_pad,cmap='viridis', \
    extent=[xobj[0,0,ind]*1e3,xobj[0,-1,ind]*1e3,yobj[0,0,ind]*1e3,yobj[-1,0,ind]*1e3])
axs[0].set_xlabel(r'$x/R$ (mrad)',fontsize=10)
axs[0].set_ylabel(r'$y/R$ (mrad)',fontsize=10) 
axs[0].tick_params(axis='both',labelsize=10)
axs[0].set_xlim([-1.5*np.size(USAF,1)*dobj[ind]/2*1e3,1.5*np.size(USAF,1)*dobj[ind]/2*1e3])
axs[0].set_ylim([-1.5*np.size(USAF,0)*dobj[ind]/2*1e3,1.5*np.size(USAF,0)*dobj[ind]/2*1e3])         

axs[1].imshow(Im,cmap='viridis', \
    extent=[xobj[0,0,ind]*1e3,xobj[0,-1,ind]*1e3,yobj[0,0,ind]*1e3,yobj[-1,0,ind]*1e3])
axs[1].set_xlabel(r'$x/R$ (mrad)',fontsize=10)
axs[1].set_ylabel(r'$y/R$ (mrad)',fontsize=10) 
axs[1].tick_params(axis='both',labelsize=10)
axs[1].set_xlim([-1.5*np.size(USAF,1)*dobj[ind]/2*1e3,1.5*np.size(USAF,1)*dobj[ind]/2*1e3])
axs[1].set_ylim([-1.5*np.size(USAF,0)*dobj[ind]/2*1e3,1.5*np.size(USAF,0)*dobj[ind]/2*1e3])         

axs[2].imshow(Iim,cmap='viridis', \
    extent=[xdet[0,0]*1e6,xdet[0,-1]*1e6,ydet[0,0]*1e6,ydet[-1,0]*1e6])
axs[2].set_xlabel(r'$x$ (microns)',fontsize=10)
axs[2].set_ylabel(r'$y$ (microns)',fontsize=10) 
axs[2].tick_params(axis='both',labelsize=10)
axs[2].set_xlim([-200,200])
axs[2].set_ylim([-200,200])         
plt.show()

plt.semilogy(xpsf[int(N/2),:,0]*1e3,PSF[int(N/2),:,0],'-b',label=r'$\lambda$ = {} $\mu$m'.format(np.round(wvl[0]*1e6,2)))
plt.semilogy(xpsf[int(N/2),:,1]*1e3,PSF[int(N/2),:,1],'-g',label=r'$\lambda$ = {} $\mu$m'.format(np.round(wvl[1]*1e6,2)))
plt.semilogy(xpsf[int(N/2),:,2]*1e3,PSF[int(N/2),:,2],'-r',label=r'$\lambda$ = {} $\mu$m'.format(np.round(wvl[2]*1e6,2)))
plt.xlim([-10*wvl[ind]/D*1e3,10*wvl[ind]/D*1e3])
plt.ylim([1e-6,1])
plt.xlabel(r'$x/f$ (mrad)')
plt.ylabel(r'PSF')
plt.legend(fancybox=False,edgecolor='black',framealpha=1)
plt.grid()
plt.show()   

