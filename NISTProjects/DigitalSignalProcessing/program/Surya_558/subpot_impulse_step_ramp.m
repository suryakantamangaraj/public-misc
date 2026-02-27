clc
clear all;
close all;
[del,n]=impseq(0,-15,15)
[s,n]=step(0,-15,15)
[r,n]=rampseq(0,-15,15)
subplot(3,1,1)
stem(n,del),
xlabel('n in sec')
ylabel('amplitude')
title('discrete unit impulse')
subplot(3,1,2)
stem(n,s)
xlabel('n in sec')
ylabel('amplitude')
title('discrete unit step')
subplot(3,1,3)
stem(n,r)
xlabel('n in sec')
ylabel('amplitude')
title('discrete unit ramp')