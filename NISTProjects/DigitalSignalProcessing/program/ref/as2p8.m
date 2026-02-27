clc;
clear all;
close all;

n=-2:1;
x=[1,4,1,3];
[x1,n1]=sigfold(x,n);
[rxx,nxx]=conv_m(x,n,x1,n1);
subplot(3,1,1);
stem(n,x);

xlabel('<-time->');
ylabel('<-amp->');
title('<-8->');

subplot(3,1,2);
stem(n1,x1);

xlabel('<-time->');
ylabel('<-amp->');
title('<-8->');

subplot(3,1,3);
stem(nxx,rxx);

xlabel('<-time->');
ylabel('<-amp->');
title('<-8->');


