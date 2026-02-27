clc
close all
clear all
x=[2,4,-3,1,-5,4,7]
n=0:6
[x1,n1]=sigshift(x,n,3)
x1=2.*x1
[x2,n2]=sigshift(x,n,-4)
x2=3.*x2
[y,n3]=sigadd(x1,n1,x2,n2);
[y1,n4]=sigadd(y,n3,-x,n)
stem(y1,n4)

