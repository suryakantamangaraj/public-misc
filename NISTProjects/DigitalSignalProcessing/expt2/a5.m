clc;
clear all;
close all;
 
x=[3,11,7,0,-1,4,2];
n=-3:3;
[y1,n1]=sigshift(x,n,2);
w=randn(1,length(n));
[y2,n2]=sigadd(y1,n1,w,n);
[y3,n3]=sigfold(y2,n2);
[y4,n4]=convo(x,n,y3,n3);
stem(n4,y4);
 
xlabel('<-time->');
ylabel('<-amp->');
title('<-5->');
