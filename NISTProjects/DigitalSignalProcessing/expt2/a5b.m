clc;
clear all;
close all;
 
x=[3,11,7,0,-1,4,2];
n=-3:3;
[y1,n1]=sigshift(x,n,2);
w=randn(1,length(n));
[y2,n2]=sigadd(y1,n1,w,n);
[x3,n3]=sigfold(x,n);
[y4,n4]=convo(x3,n3,y2,n2);
[y5,n5]=sigfold(y4,n4);
stem(n5,y5);
 
xlabel('<-time->');
ylabel('<-amp->');
title('<-5b->');
