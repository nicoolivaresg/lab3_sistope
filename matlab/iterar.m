function [ grid2 ] = iterar( N, I )
%UNTITLED7 Summary of this function goes here
%   Detailed explanation goes here

    c =1.0;
    dd=0.1;
    dt=2.0;
    
    grid0 = create_grid(N);
    grid1 = create_grid(N);
    grid2 = create_grid(N);

    grid0 = init_grid(grid0,N,20);
    grid1 = init_grid(grid1,N,0);
    grid2 = init_grid(grid2,N,0);
    
    %Primera iteracion
    for i = 1:N
        for j = 1:N
            if (i == 1 || j == 1 || i == N || j == N )
                %bordes
                grid1(i,j) = 0;
            else
                %Formula para iteracion uno
                grid1(i,j) = grid0(i,j) + (0.5*c^2)*((dd/dt)^2)*factor(grid0, i, j);
            end     
        end
    end
    %Resto de iteraciones
    for iteracion = 3:I
        for i = 1:N
            for j = 1:N
                if (i == 1 || j == 1 || i == N || j == N )
                    
                else
                    grid2(i,j) = 2*grid1(i,j) - grid0(i,j) +  (c^2)*((dd/dt)^2)*factor(grid1, i, j);
                end     
            end
        end
        grid0 = traspasar_grid(grid1);
        grid1 = traspasar_grid(grid2);
    end
end

