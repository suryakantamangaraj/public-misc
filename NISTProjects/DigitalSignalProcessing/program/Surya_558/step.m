function [ s,n ] = step( k,n1,n2 )
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
n=n1:n2

s=[(n-k)>=0]
end
