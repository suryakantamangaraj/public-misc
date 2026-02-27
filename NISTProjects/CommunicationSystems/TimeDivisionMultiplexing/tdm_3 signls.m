clc;
close all;
clear all;
 
x=0:.5:4*pi;                             
sig1=8*sin(x);                           
l=length(sig1);
sig2=8*triang(l);
sig3=8*square(1:l);
 
subplot(2,3,1);                          
plot(sig1);
title('Sinusoidal Signal');
ylabel('Amplitude--->');
xlabel('Time--->');
subplot(2,3,2);
plot(sig2);
title('Triangular Signal');
ylabel('Amplitude--->');
xlabel('Time--->');
subplot(2,3,3);
plot(sig3);
title('square Signal');
ylabel('Amplitude--->');
xlabel('Time--->');
 
subplot(2,3,4);
stem(sig1);
title('Sampled Sinusoidal Signal');
ylabel('Amplitude--->');
xlabel('Time--->');
subplot(2,3,5);
stem(sig2);
title('Sampled Triangular Signal');
ylabel('Amplitude--->');
xlabel('Time--->');
subplot(2,3,6);
stem(sig3);
title('Sampled square Signal');
ylabel('Amplitude--->');
xlabel('Time--->');
l1=length(sig1);
l2=length(sig2);
l3=length(sig3);
 for i=1:l1
  sig(1,i)=sig1(i);                     
  sig(2,i)=sig2(i);
  sig(3,i)=sig3(i);
 end  
 
 
tdmsig=reshape(sig,1,3*l1);               
 
figure
stem(tdmsig);
title('TDM Signal');
ylabel('Amplitude--->');
xlabel('Time--->');
 
 
 demux=reshape(tdmsig,3,l1);
 for i=1:l1
  sig4(i)=demux(1,i);                   
  sig5(i)=demux(2,i);
  sig6(i)=demux(3,i);
 end  
 
 figure
 subplot(3,1,1)
 plot(sig4);
 title('Recovered Sinusoidal Signal');
 ylabel('Amplitude--->');
 xlabel('Time--->');
 subplot(3,1,2)
 plot(sig5);
 title('Recovered Triangular Signal');
 ylabel('Amplitude--->');
 xlabel('Time--->');
 subplot(3,1,3)
  plot(sig6);
 title('Recovered square Signal');
 ylabel('Amplitude--->');
 xlabel('Time--->');
