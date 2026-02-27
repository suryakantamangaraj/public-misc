clc;
clear all;
close all;
[x,n]=impseq(0,-5,15);
[x1,n1]=sigshift(x,n,-2);
x1=2.*x1;
[x2,n2]=sigshift(x,n,4);
[y3,n3]=sigadd(x1,n1,-x2,n2);
stem(n3,y3)