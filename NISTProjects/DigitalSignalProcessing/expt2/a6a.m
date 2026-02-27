clc;
clear all;
close all;
 
[x1,n1]=impseq(0,-5,5);
[x2,n2]=impseq(1,-5,5);
[x3,n3]=impseq(2,-5,5);
[y1,n4]=sigadd(x1,n1,x2,n2);
[y2,n5]=sigadd(y1,n4,x3,n3);
y=(1/3).* y2;
stem(n5,y);
 
xlabel('<-time->');
ylabel('<-amp->');
title('<-6a->');
