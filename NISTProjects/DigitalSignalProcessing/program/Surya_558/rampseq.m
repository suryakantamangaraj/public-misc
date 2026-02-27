function [ r,n ] = rampseq( k,n1,n2 )
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
n=n1:n2

r=n.*[(n-k)>=0]
end
