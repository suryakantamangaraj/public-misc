function [xn]=idft(XK,N)
    n=0:N-1;
    k=0:N-1;
    WN=exp(-j*2*pi/N);
    nk=n'*k;
    wNnk=WN.^-nk;
    xn=1/N*XK*wNnk;
end

