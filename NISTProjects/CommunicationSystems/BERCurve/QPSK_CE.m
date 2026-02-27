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
semilogy(ebno,ber);
%thber=1/2.*erfc(sqrt(eb/no));
%semilogy(ebno,thber);
xlabel('power in desibel');
ylabel('bit error rate');
title('ber curve');