clc
close all
clear all
x=[1 2 3 4 4 3 2 1]
N=8;
y1=butterfly_dif(x,N)
y2=[]
for i=1:N/2:N
    g2=[y1(i:i+3)]
    z2=butterfly_dif(g2,N/2)
    y2=[y2 z2]
end
y3=[]
for i=1:N/4:N
    g=[y2(i),y2(i+1)]
    z3=butterfly_dif(g,N/4)
    y3=[y3 z3]
end
y3=bitrevorder(y3)
