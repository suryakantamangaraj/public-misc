clc;
close all;
clear all;
n1=-20
n2=20
[x1,n1]=step(0,n1,n2);
x1=10.*x1;
[x2,n2]=step(5,n1,n2);
x2=5.*x2;
[x3,n3]=step(10,n1,n2);
x3=10.*x3;
[x4,n4]=step(15,n1,n2);
x4=5.*x4;
[y5,n5]=sigadd(x1,n1,-x2,n2);
[y6,n6]=sigadd(-x3,n3,x4,n4);
[y7,n7]=sigadd(y5,n5,y6,n6);
stem(n7,y7);

