function [grid_destino] = traspasar_grid( grid_origen )
%UNTITLED6 Summary of this function goes here
%   Detailed explanation goes here
    N = length(grid_origen);
    grid_destino = zeros(N,'double');
    for i = 1:N
        for j = 1:N
            grid_destino(i,j) = grid_origen(i,j);     
        end
    end
end

