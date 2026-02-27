clc
clear all;
close all;
b=[2,-1]
a=[1,-0.1,-0.02]
n=0:7
x1=step(0,0,7)
x1=2.*x1
x2=step(1,0,7)
x=x1-x2
y=[-10,5]
yic=filtic(b,a,y)
y=filter(b,a,x,yic)