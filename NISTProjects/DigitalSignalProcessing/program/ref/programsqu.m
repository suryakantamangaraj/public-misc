clc;
clear all;
close all;
t = 0:.0001:.0625;
y = square(2*pi*30*t);
plot(t,y);
xlabel('time in sec');
ylabel('amplitude');