
timesfilename = 'times.csv';
efficiencyfilename = 'efficiency.csv';
speedupfilename = 'speedup.csv';
times = csvread(timesfilename,0,2);
efficiency = csvread(efficiencyfilename,0,2);
speedup = csvread(speedupfilename,0,2);
N = size(times,1);
times = times';
efficiency = efficiency';
speedup = speedup';
x =[1 2 3 4 5 6 7 8 9 10 11 12 13 14];
y =[];
titulos = {'128x128 2000 Iteraciones', '128x128 4000 Iteraciones', '128x128 8000 Iteraciones',  '256x256 2000 Iteraciones', '256x256 4000 Iteraciones', '256x256 8000 Iteraciones'};
for i = 1:N
    y = times(:,i);
    createfigure(x,y,titulos{i},'Tiempos/hebra','tiempo','Tiempo [s]');
    y = efficiency(:,i);
    createfigure(x,y,titulos{i},'Eficiencia','eficiencia','Eficiencia');
    y = speedup(:,i);
    createfigure(x,y,titulos{i},'speedup','speedup','Speedup');
end

iteraciones = [2000 4000 8000];
tamanos = [128 256];
resultados = [];
k = 1;
for i=1:length(tamanos)
    for j=1:length(iteraciones)
        N= tamanos(i);
        I= iteraciones(j);
        resultado = iterar(N,I);
        createfigure1(resultado,strcat('Grilla final ',titulos{k}));
        k = k + 1;
    end
end