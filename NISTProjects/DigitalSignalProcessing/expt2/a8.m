clc;
clear all;
close all;
 
x=[1,4,1,3];
n=-2:1;
[x1,n1]=sigfold(x,n)
[y2,n2]=convo(x,n,x1,n1);
stem(n2,y2);

xlabel('<-time->');
ylabel('<-amp->');
title('<-8->');
