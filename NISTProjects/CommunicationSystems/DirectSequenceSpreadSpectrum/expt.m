clc;
close all;
clear all;
N=10;
b=randi([0,1],N);
ln=length(b);
for i=1:ln
    if b(i)==0
        b(i)=-1;
    end
end
k=1;
for i=1:ln
    for j=1:8
        bb(k)=b(i);
        j=j+1;
        k=k+1;
    end
    i=i+1;
end
len=length(bb);
subplot(2,1,1);
stem(bb,'linewidth',2);
axis([0 len -2 3]);
title('ORIGINAL BIT SEQUENCE b(t)');
pr_sig=round(rand(1,len));
for i=1:len
    if pr_sig(i)==0
        pr_sig(i)=-1;
    end
end
subplot(2,1,2);
stairs(pr_sig,'linewidth',2);
axis([0 len -2 3]);
title('PSEUDORANDOM BIT SEQUENCE pr_sig(t)');
for i=1:len
    bbs(i)=bb(i).*pr_sig(i);
end
dsss=[];
t=0:1/10:2*pi;
c1=cos(t);
c2=cos(t+pi);
for k=1:len
    if bbs(1,k)==-1;
        dsss=[dsss c1];
    else
        dsss=[dsss c2];
    end
end
figure
subplot(2,1,1);
stairs(bbs,'linewidth',2);
axis([0 len -2 3]);
title('MULTIPLIER OUTPUT SEQUENCE b(t)*pr_sig(t)');
subplot(2,1,2);
plot(dsss);
axis([0 1000 -1 1]);
title(' DS-SS SIGNAL...');
