clc;
clear all;
close all;
nx=-3:3;
nh=-1:4;
x=[3,11,7,0,-1,4,2];
h=[2,3,0,-5,2,1];
[y,n1]=conv_m(x,nx,h,nh)
stem(n1,y);