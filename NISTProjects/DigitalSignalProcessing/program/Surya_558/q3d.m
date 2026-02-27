clc
close all
clear all
x=[2,4,-3,1,-5,4,7]
n=-10:10
pi=3.141
p=0.5.*(n)
m=exp(p)
x1=x.*m
x1=2.*x1
[x2,n2]=sigshift(x,n,-2)
x2=cos(0.1.*(n).*pi).*x2
[y,n3]=sigadd(x1,n,x2,n2);
stem(y1,n3)

