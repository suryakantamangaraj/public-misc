clc
clear all;
close all;
[del,n]=impseq(2,-15,15)
stem(n,del)
xlabel('n in sec')
ylabel('amplitude')
title('discrete unit impulse')