#include "thread_handler.h"
#include "wave_generator.h"
#include <math.h>
#include <assert.h>


int main(int  argc, char ** argv){
	int Nflag = 0; //Flag tamaño de la grilla
	int Tflag = 0; //Flag número de pasos
	int Hflag = 0; //Flag número de hebras
	int fflag = 0; //Flag archivo de salida
	int tflag = 0; //Flag iteraciones de salida
	int threads = 0;
	int gridSize = 0; // N
	int steps = 0;
	int iterations = 0 ;
	char * outputFilename = NULL;
	int c, i;
	opterr=0;
	while((c = getopt(argc,argv,"N:T:H:f:t:")) != -1){
		switch(c){
			case 'N':
				Nflag = 1;
				sscanf(optarg, "%d", &gridSize);
				break;
			case 'T':
				Tflag = 1;
				sscanf(optarg, "%d", &steps);
				break;
			case 'H':
				Hflag = 1;
				sscanf(optarg, "%d", &threads);
				break;
			case 'f':
				fflag = 1;
				outputFilename = malloc(strlen(optarg)+1);
				strcpy(outputFilename,optarg);
				break;
			case 't':
				tflag = 1;
				sscanf(optarg, "%d", &iterations);
				break;
			case '?':
				if((optopt == 'N') || (optopt == 'T') || (optopt == 'H') || (optopt == 'f') || (optopt == 't')){
					fprintf(stderr, "Opcion -%c requiere un argumento.\n", optopt);
				}else if(isprint(optopt)){
					fprintf(stderr, "Opcion desconocida '-%c'.\n", optopt);
				}else{
					fprintf(stderr, "Opcion con caracter desconocido '\\x%x'.\n", optopt);
				}
				return 1;
			default:
				abort();
		}
	}
	//En caso de que falten argumentos en la linea de comando
	if(argc < 11){
		printf("Faltan parametros para ingresar\n");
		return 1;
	}
	/*
	printf("Nflag = %d, Tflag = %d, Hflag = %d, fflag = %d, tflag = %d\n", Nflag, Tflag, Hflag, fflag, tflag);
	printf("Tamaño de la grilla: %d\nPasos: %d\nHebras: %d\nArchivo de salida: %s\nIteraciones salida: %d\n", 
		gridSize,
		steps,
		threads,
		outputFilename,
		iterations
		);*/
	/*
	*/
	/*
		Procesamiento
	*/

	// Abrir el archivo de salida y comprobar que no hay problemas
	FILE* outputFile = fopen(outputFilename, "wb");
	if(outputFile == NULL) {
		printf("No se pudo abrir el archivo %s\n", outputFilename);
		return 1;
	}

	// Las grillas son 3, usando % se hace un bucle a traves de estas tres grillas.
	// Reserva de memoria para grillas
	for (i = 0; i < 3; ++i) {
		grids[i] = allocate_grid_memory(gridSize);
	}
	// Rellenado de matrices
	grids[0] = initialize_grid(grids[0], gridSize, 20);
	grids[1] = initialize_grid(grids[1], gridSize, 0);
	grids[2] = initialize_grid(grids[2], gridSize, 0);
	
	// Crear hebras
	// Primero se debe calcular la cantidad de filas que debe calcular cada hebra
	int rowsLeft = gridSize;
	int threadsLeft = threads;

	if(threads > gridSize){
		threads = gridSize;
	}
	int startingRow = 0;

	WGThread* wgthreads = malloc(threads * sizeof(*wgthreads));
	for (i = 0; i < threads; ++i) {
		int rowsPerThread = (int)ceil((float) rowsLeft / threadsLeft);
		if(rowsLeft - rowsPerThread < 0) {
			rowsPerThread = rowsLeft;
		}
		WGThread_init(&(wgthreads[i]), i+1, gridSize, rowsPerThread, startingRow, iterations);

		rowsLeft -= rowsPerThread;
		startingRow += rowsPerThread;
		threadsLeft--;
	}

	// Inicializar la barrera antes de correr las hebras
	pthread_barrier_init(&barrier, NULL, threads);

	// Correr la primera iteracion y esperar con join
	for(i = 0; i < threads; i++) {
		pthread_create(&(wgthreads[i].thread), NULL, first_iteration, (void*) &(wgthreads[i]));
	}
	for(i = 0; i < threads; i++) {
		pthread_join( wgthreads[i].thread, NULL);
	}

	// Correr todas las iteraciones que faltan y esperar con join
	for(i = 0; i < threads; i++) {
		pthread_create(&(wgthreads[i].thread), NULL, other_iterations, (void*) &(wgthreads[i]));
	}
	for(i = 0; i < threads; i++) {
		pthread_join( wgthreads[i].thread, NULL);
	}


	// Escribir los resultados que se encuentran en grids[t%3] en un archivo
	//show_grid(grids[iterations % 3], gridSize);
	for (i = 0; i < gridSize; ++i) {
		fwrite(grids[iterations % 3][i], sizeof(grids[iterations % 3][0]), gridSize, outputFile);
	}
	

	// Free memory
	free(outputFilename);
	free(wgthreads);
	for (i = 0; i < gridSize; i++)
	{
		free(grids[0][i]);
		free(grids[1][i]);
		free(grids[2][i]);
	}
	free(grids[0]);
	free(grids[1]);
	free(grids[2]);

	fclose(outputFile);

	
	return 0;
}

