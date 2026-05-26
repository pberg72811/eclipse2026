serialportObj = serialport("COM10",9600);
for ii = 1:10240, 
  data1 = read(serialportObj,32,"uint8"); 
  disp(data1);
  disp("HELLO")
  pause(.025);
end

clear all
close all