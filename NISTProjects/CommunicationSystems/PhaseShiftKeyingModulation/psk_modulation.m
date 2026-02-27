clear all;
clc;
close all;
set(0,'defaultlinelinewidth',2);
A=5;
t=0:.001:1;
f1=input('Carrier Sine wave frequency =');
f2=input('Message frequency =');
x=A.*sin(2*pi*f1*t);%Carrier Sine
subplot(3,1,1);
plot(t,x);
xlabel('time');
ylabel('Amplitude');
title('Carrier');
grid on;
u=square(2*pi*f2*t);%Message signal
subplot(3,1,2);
plot(t,u);
xlabel('time');
ylabel('Amplitude');
title('Message Signal');
grid on;

v=x.*u;%Sine wave multiplied with square wave
subplot(3,1,3);
plot(t,v);
axis([0 1 -6 6]);
xlabel('t');
ylabel('y');
title('PSK');
grid on;