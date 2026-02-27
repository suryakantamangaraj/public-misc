clc;
clear all;
close all;
 
[x1,n1]=imp1(0,-5,5);
[x2,n2]=imp1(1,-5,5);
[x3,n3]=imp1(2,-5,5);
[y1,n4]=sigadd(x1,n1,x2,n2);
[y2,n5]=sigadd(y1,n4,x3,n3);
y3=(1/3).* y2;
 
[u,n]=step1(0,0,10);
[u6,n6]=convo(y3,n5,u,n);
stem(n6,u6);
 
xlabel('<-time->');
ylabel('<-amp->');
title('<-6b->');
