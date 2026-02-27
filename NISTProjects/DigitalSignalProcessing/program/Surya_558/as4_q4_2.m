clc
clear all;
close all;
b=[1]
a=[1 -1.5 0.5]
n=0:7
x1=(1/4).^n
[x,n]=step(0,0,7)
x=x1.*x
y=[4 0]
yic=filtic(b,a,y)
y=filter(b,a,x,yic)