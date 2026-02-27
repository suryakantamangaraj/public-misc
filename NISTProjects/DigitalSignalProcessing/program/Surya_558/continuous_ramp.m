clc;
clear all;
close all;
t=-5:5;

 x=t.*[(t>=0)]
% x=[]
% if(t>=0)
%     
%     x(t)=t
% end

plot(t,x);
xlabel('t in sec');
ylabel('amplitude');
title('continuous ramp');