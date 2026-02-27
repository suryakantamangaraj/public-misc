b=[1]
a=[1 -1.5 0.5]
n=0:10
x1=(1/4).^n
[x,n]=step(0,0,10)
x=x1.*x
y=filter(b,a,x)