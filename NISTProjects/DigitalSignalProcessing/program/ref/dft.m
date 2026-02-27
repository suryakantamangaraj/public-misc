function [XK]=dft(xn,N)
xn=[xn,zeros(1,N-length(xn))]
    n=0:N-1;
    k=0:N-1;
    wN=exp(-j*2*pi/N);
    nk=n'*k;
    wNnk=wN.^nk;
    XK=xn*wNnk;
end

