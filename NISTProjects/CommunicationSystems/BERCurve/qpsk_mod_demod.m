clc;
clear all;
close all;

m=4;
n=10^5;
xr=randi([0 m-1],m,n);
ebno=[0:20];

for i=1:length(ebno);
    xm=pskmod(xr,m,0);
    yo=awgn(xm,ebno(i));
    xdm=pskdemod(yo,m);
    err(i)=symerr(xr,xdm);
end

ber=err/n;
grid on;
semilogy(ebno,ber,':gx',...
    'linewidth',3);

hold on;

thber=1/2.*erfc(sqrt(ebno));
grid on;

semilogy(ebno,thber,'-r*',...
    'linewidth',1);

legend('simulated BER','theoretical BER');
xlabel('eb/no in dB');
ylabel('bit error rate in dB');
title('BER curve for QPSK');
axis([0 14 0.0000001 1]);