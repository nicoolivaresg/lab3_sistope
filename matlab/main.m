askForN = 'Ingrese el tamaño del grid: ';
N = input(askForN);
askForT = 'Ingrese el número de iteraciones: ';
t = input(askForT);

ultimaIteracion = iterar(N,t);
%subplot(2,2,1);
imagesc(ultimaIteracion);
axis('off');

%f = fopen('output.raw','wb');
%fwrite(f, grid ,'double')
%fclose(f);

