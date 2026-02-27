clc;
clear all;
close all;
N=5;
n=-N:N;
x=ones(1,length(n));
[y,n1]=conv_m(x,n,x,n);
stem(n1,y);
