function [ grid ] = init_grid( grid, N, H )
%UNTITLED4 Summary of this function goes here
%   Detailed explanation goes here
    leftLimit = floor(N*40/100);
    rightLimit = floor(N*60/100);
    
    i= 1;
    while i<N
        j = 1;
        while j<N
            if i>leftLimit && i<rightLimit && j>leftLimit && j<rightLimit
                grid(i,j) = H;
            else
                grid(i,j) = 0;
            end
            j=j+1;
        end
        i=i+1;
    end


end

