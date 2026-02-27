clc
clear all;
close all;

n=-20:100;
a=[1,-1,0.9];
b=[1];
h=impz(b,a,n);
[x,n]=impseq(0,-20,100);
h=filter(b,a,x);
stem(n,h);

xlabel('<-time->');
ylabel('<-amp->');
title('<-9b->');