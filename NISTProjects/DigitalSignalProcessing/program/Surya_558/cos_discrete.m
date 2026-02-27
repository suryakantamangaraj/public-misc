clc
clear all;
close all;
A=input('enter the value of A');
f=input('enter the value of f');
n=-10:10;
w=2*pi*f;
x=A.*cos(w.*n);
stem(n,x);
xlabel('n in sec');
ylabel('amplitude');
title('discrete coswave');