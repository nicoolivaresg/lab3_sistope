function [ f ] = factor(grid, i, j)
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
    f = (grid(i-1,j) + grid(i+1,j) + grid(i,j+1) + grid(i,j-1)-4*grid(i,j));

end