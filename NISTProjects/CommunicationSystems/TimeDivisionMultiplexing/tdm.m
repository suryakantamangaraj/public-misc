clc;
close all;
clear all;
 
x=0:.1:4*pi;

sig1=8*sin(x);                           
l=length(sig1);

sig2=8*triang(l);

sig3=8*square(1:l);

sig4=8*cos(x);
 
subplot(2,4,1);                          
plot(sig1);
title('Sinusoidal Signal');
ylabel('Amplitude--->');
xlabel('Time--->');
axis([0 130 -10 10]);

subplot(2,4,2);
plot(sig2);
title('Triangular Signal');
ylabel('Amplitude--->');
xlabel('Time--->');
axis([0 130 0 8]);

subplot(2,4,3);
plot(sig3);
title('square Signal');
ylabel('Amplitude--->');
xlabel('Time--->');
axis([0 130 -10 10]);

subplot(2,4,4);
plot(sig4);
title('cosine Signal');
ylabel('Amplitude--->');
xlabel('Time--->');
axis([0 130 -10 10]);
  
subplot(2,4,5);
stem(sig1);
title('Sampled Sinusoidal Signal');
ylabel('Amplitude--->');
xlabel('Time--->');
axis([0 130 -10 10]);

subplot(2,4,6);
stem(sig2);
title('Sampled Triangular Signal');
ylabel('Amplitude--->');
xlabel('Time--->');
axis([0 130 0 8]);

subplot(2,4,7);
stem(sig3);
title('Sampled square Signal');
ylabel('Amplitude--->');
xlabel('Time--->');
axis([0 130 -10 10]);

subplot(2,4,8);
stem(sig4);
title('Sampled cosine Signal');
ylabel('Amplitude--->');
xlabel('Time--->');
axis([0 130 -10 10]);

l1=length(sig1);
l2=length(sig2);
l3=length(sig3);
l4=length(sig4);

 for i=1:l1
  sig(1,i)=sig1(i);                     
  sig(2,i)=sig2(i);
  sig(3,i)=sig3(i);
  sig(4,i)=sig4(i);
 end  
 
tdmsig=reshape(sig,1,4*l1);               
 
figure
stem(tdmsig);
title('TDM Signal');
ylabel('Amplitude--->');
xlabel('Time--->');
axis([0 530 -8 8]);
 
 
 demux=reshape(tdmsig,4,l1);
 
 for i=1:l1
  sig5(i)=demux(1,i);                   
  sig6(i)=demux(2,i);
  sig7(i)=demux(3,i);
  sig8(i)=demux(4,i);
 end  
 
 figure
 subplot(4,1,1)
 plot(sig5);
 title('Recovered Sinusoidal Signal');
 ylabel('Amplitude--->');
 xlabel('Time--->');
 axis([0 130 -10 10]);
 
 subplot(4,1,2)
 plot(sig6);
 title('Recovered Triangular Signal');
 ylabel('Amplitude--->');
 xlabel('Time--->');
 axis([0 130 0 8]);
 
 subplot(4,1,3)
  plot(sig7);
 title('Recovered square Signal');
 ylabel('Amplitude--->');
 xlabel('Time--->');
 axis([0 130 -10 10]);
 
  subplot(4,1,4)
  plot(sig8);
 title('Recovered cosine Signal');
 ylabel('Amplitude--->');
 xlabel('Time--->');
 axis([0 130 -10 10]);
