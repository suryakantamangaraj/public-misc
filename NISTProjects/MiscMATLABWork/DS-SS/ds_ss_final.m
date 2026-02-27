clc;
close all;
clear all;

x=input('Enter The input Bits : ');
b=randi([0,1],x);
len=length(b);

%to get NRZ data bit 0 to -1 is  converting
for i=1:len
    if b(i)==0
        b(i)=-1;
    end
end
k=1;

% Generating the bit sequence of 6 samples
for i=1:len
    for j=1:6
        b1(k)=b(i);
        j=j+1;
        k=k+1;
    end
    i=i+1;
end
len1=length(b1);
subplot(2,1,1);
stairs(b1,'linewidth',2);
axis([0 len1 -2 3]);
title('ORIGINAL BIT SEQUENCE b(t)');

% Generating the pseudo random sequence
c=round(rand(1,len1));
for i=1:len1
    if c(i)==0
        c(i)=-1;
    end
end
subplot(2,1,2);
stairs(c,'linewidth',2);
axis([0 len1 -2 3]);
title('PSEUDORANDOM SEQUENCE c(t)');

% Multiplying data bit with Pseudo random Sequence
for i=1:len1
    b2(i)=b1(i).*c(i);
end

% Modulating the multiplyed signal
dsss=[];
t=0:1/10:2*pi;
m1=cos(t);
m2=cos(t+pi);
for k=1:len1
    if b2(1,k)==-1;
        dsss=[dsss m1];
    else
        dsss=[dsss m2];
    end
end
figure
subplot(2,1,1);
stairs(b2,'linewidth',2);
axis([0 len1 -2 3]);
title('MULTIPLIER OUTPUT SEQUENCE b(t)*c(t)');
subplot(2,1,2);
plot(dsss);
axis([0 1000 -1 1]);
title(' DS-SS SIGNAL');
