clc
clear all;
close all;

n=-20:100;
a=[1,-1,0.9];
b=[1];
h=impz(b,a,n);
stem(n,h);
z=sum(abs(h));

xlabel('<-time->');
ylabel('<-amp->');
title('<-9a->');