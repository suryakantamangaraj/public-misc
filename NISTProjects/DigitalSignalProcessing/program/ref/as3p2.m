clc;
clear all;
close all;

x1=[2,1,2,1]
N=4
[XK1]=dft(x1,N)
x2=[1,2,3,4]
[XK2]=dft(x2,N)
XK=XK1.*XK2
[xn]=idft(XK,N)

