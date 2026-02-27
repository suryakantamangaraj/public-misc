clc;
clear all;
close all;
 
x=[3,11,7,0,-1,4,2];
nx=-3:3;
h=[2,3,0,-5,2,1];
nh=-1:4;
[y,n]=convo(x,nx,h,nh);
stem(n,y);
 
xlabel('<-time->');
ylabel('<-amp->');
title('<-4->');
