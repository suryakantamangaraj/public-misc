clc;
clear all;
close all;
 
n=-10:10;
a=0.1+0.3i;
x=exp(a.*n);
 
a=abs(x);
b=real(x);
c=imag(x);
d=angle(x);
 
subplot(221);
stem(n,a);
title('abs');
xlabel('<--time-->');
ylabel('<--amp-->');
 
subplot(222);
stem(n,b);
title('real');
xlabel('<--time-->');
ylabel('<--amp-->');
 
subplot(223);
stem(n,c);
title('imag');
xlabel('<--time-->');
ylabel('<--amp-->');
 
subplot(224);
stem(n,d);
title('angle');
xlabel('<--time-->');
ylabel('<--amp-->');
