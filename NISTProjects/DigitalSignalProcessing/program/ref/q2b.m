clc;
clear all;
close all;
n1=0;
n2=20;
n=0:59;
[x1,n1]=stepseq(0,n1,n2);
[x2,n2]=stepseq(20,n1,n2);
[y,n]=sigadd(x1,n1,-x2,n2);
y=y.*exp(0.1*n);
xtilde=y'*ones(1,3);
xtilde=xtilde(:)
xtilde=xtilde';
stem(xtilde);