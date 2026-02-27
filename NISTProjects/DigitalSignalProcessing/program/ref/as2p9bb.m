clc
clear all;
close all;

n=-20:100;
a=[1,-1,0.9];
b=[1];
h=impz(b,a,n);
[x,n]=stepseq(0,-20,100);
y=filter(b,a,x);
stem(n,y);

xlabel('<-time->');
ylabel('<-amp->');
title('<-9c->');