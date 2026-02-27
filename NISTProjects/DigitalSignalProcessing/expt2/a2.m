clc;
clear all;
close all;
 
n=-5:5;
x=ones(1,length(n));
[y,n]=convo(x,n,x,n);
stem(n,y);
 
xlabel('<-time->');
ylabel('<-amp->');
title('<-2->');
