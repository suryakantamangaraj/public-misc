clc;
clear all;
close all;
n=-15:15;

 x=n.*[(n>=0)]
% x=[]
% if(t>=0)
%     
%     x(t)=t
% end

stem(n,x);
xlabel('t in sec');
ylabel('amplitude');
title('continuous ramp');