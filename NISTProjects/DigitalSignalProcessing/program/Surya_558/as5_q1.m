clc
close all
clear all
v=[1 1 1 1 1 1 1 1]
x=bitrevorder(v)
N=8;
z=[]
for i=1:N/4:N
    g=[x(i),x(i+1)]
    y=butterfly_dit(g,N/4)
    z=[z y]
end
z1=[]
for i=1:N/2:N
    g1=[z(i:i+3)]
    y1=butterfly_dit(g1,N/2)
    z1=[z1 y1]
end
[z2]=butterfly_dit(z1,N)
z2
