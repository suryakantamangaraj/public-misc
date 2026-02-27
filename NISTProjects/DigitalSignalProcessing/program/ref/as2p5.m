clc;
clear all;
close all;
x=[3,11,7,0,-1,4,2];
n=-3:3;
[y1,n1]=sigshift(x,n,2);
w=randn(1,length(n1));
y=y1+w;
%folding of x(n)
[x1,nx]=sigfold(x,n);
%folding of y(n)
[y2,n2]=sigfold(y,n1)
[rxy,nxy]=conv_m(x,n,y2,n2);
[ryx,nyx]=conv_m(y,n1,x1,nx);
[ryx1,nyx1]=sigfold(ryx,nyx);
subplot(2,2,1)
plot(nxy,rxy);
subplot(2,2,2);
plot(nyx,ryx);
subplot(2,2,3);
plot(nyx1,ryx1);