clc
clear all;
close all;
A=input('enter the value of A');
f=input('enter the value of f');
t=-10:0.0001:10;
w=2*pi*f;
x=A.*sin(w.*t);
plot(t,x);
xlabel('t in sec');
ylabel('amplitude');
title('continous sinwave');