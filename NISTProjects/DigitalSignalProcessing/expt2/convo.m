function [y,n] =convo(x,nx,h,nh)
n=(nx(1)+nh(1)):nx(length(nx))+nh(length(nh));
for i=1:length(n);
[h1,nh1]=sigfold(h,nh);
[h2,nh2]=sigshift(h1,nh1,n(i));
[y1,n1]=sigmul(x,nx,h2,nh2);
y(i)=sum(y1);
end
 
