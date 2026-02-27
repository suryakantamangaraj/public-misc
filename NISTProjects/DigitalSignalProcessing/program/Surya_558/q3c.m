clc
close all
clear all
x=[2,4,-3,1,-5,4,7]
n=0:6
[x1,n1]=sigshift(x,n,-3);
[x2,n2]=sigshift(x,n,2);
[x3,n3]=sigfold(x,n);
[x3,n3]=sigshift(x3,n3,1);
[x4,n4]=sigshift(x,n,-1);
[y5,n5]=sigmul(x1,n1,x2,n2);
[y6,n6]=sigmul(x3,n3,x4,n4);
[y7,n7]=sigadd(y5,n5,y6,n6);
stem(y7,n7);

