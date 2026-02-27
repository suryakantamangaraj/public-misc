function [ xe,ne,xo,no] = evenodd( x,n )
[y1,n1]=sigfold(x,n)
[xe,ne]=sigadd(x,n,y1,n1);
xe=0.5*xe
[xo,no]=sigadd(x,n,-y1,n1);
xo=0.5*xo;


end

