clc;
clear all;
close all;
t=-8:8;
x=t.*(t>=0);
plot(t,x);
xlabel('time in sec');
ylabel('amplitude');
title('ramp wave form');
