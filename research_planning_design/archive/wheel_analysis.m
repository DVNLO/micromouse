%Wheel analysis.
%The motor applies torque to the wheel by:
% Tw = (rG)*(Tml/rm)
% The goal of the analysis is to see the resulting torque values of wheels
% across the spectrum of the motor. 

wheelRadius = 2;%cm
stallTorque = 35;%mNm
resolution = .5;

rG = .5:(wheelRadius/(stallTorque/resolution)):wheelRadius;
rM = .5:(wheelRadius/(stallTorque/resolution)):wheelRadius;
Tml = 0:resolution:stallTorque;

[X,Y,Z] = meshgrid(rG,rM,Tml);
v = (X./Y).*Z;
xslice = [wheelRadius/2]; 
yslice = [wheelRadius/2]; 
zslice = stallTorque/2;
slice(X,Y,Z,v,xslice,yslice,zslice, 'nearest')
colormap hsv
shading interp
% launch sliceomatic
%sliceomatic(v,X,Y,Z);