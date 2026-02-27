clc
clear all;
close all;
A=5;
n=-10:10;
w=2*pi*0.1;
x=A.*sin(w.*n);
stem(n,x);
xlabel('n in sec');
ylabel('amplitude');
title('discrete sinwave');