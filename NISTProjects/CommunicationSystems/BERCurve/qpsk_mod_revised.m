clc;
clear all;
close all;
m=16;
n=10^3;
xr=randi([0 m-1],m,n);
ebno=[0:30];
for i=1:length(ebno);
    xm=pskmod(xr,m,0);
    yo=awgn(xm,ebno(i));
    xdm=pskdemod(yo,m);
    err1(i)=symerr(xr,xdm);
end
for i=1:length(ebno);
    xm1=qammod(xr,m,0);
    yo1=awgn(xm1,ebno(i));
    xdm1=qamdemod(yo1,m);
    err2(i)=symerr(xr,xdm1);
end

ber1=err1/n;
ber2=err2/n;


thber2=2.*erfc(sqrt(0.4*ebno));
thber1=erfc(sqrt((4*ebno)*(sin(pi/m))^2));



semilogy(ebno,thber1,'g*-');
hold on;
semilogy(ebno,ber1,'r-O');

semilogy(ebno,thber2,'g-');
semilogy(ebno,ber2,'r--');

grid on;

xlabel('power in desibel');
ylabel('bit error rate');
axis([0 30 0.01 100]);
legend('theroti16psk','simuleted16psk','theroti16qam','simuleted16qam');
title('BER curve of 16qam');

