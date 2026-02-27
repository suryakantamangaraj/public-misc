clc;
clear all;
close all;

xn=[1,2,3,4]
N=4
[XK]=dft(xn,N)
[xn]=idft(XK,N)