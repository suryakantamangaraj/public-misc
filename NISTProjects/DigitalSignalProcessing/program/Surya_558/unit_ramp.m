clc
clear all;
close all;
[r,n]=rampseq(0,-15,15)
stem(n,r)
xlabel('n in sec')
ylabel('amplitude')
title('discrete unit ramp')