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
	int grid_size = 0; // N
	int steps = 0;
	int iterations = 0 ;
	char * output_file = NULL;
	int c;
	opterr=0;
	while((c = getopt(argc,argv,"N:T:H:f:t:")) != -1){
		switch(c){
			case 'N':
				Nflag = 1;
				sscanf(optarg, "%d", &grid_size);
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
				output_file = malloc(strlen(optarg)+1);
				strcpy(output_file,optarg);
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

	printf("Nflag = %d, Tflag = %d, Hflag = %d, fflag = %d, tflag = %d\n", Nflag, Tflag, Hflag, fflag, tflag);
	printf("Tamaño de la grilla: %d\nPasos: %d\nHebras: %d\nArchivo de salida: %s\nIteraciones salida: %d\n", 
		grid_size,
		steps,
		threads,
		output_file,
		iterations
		);
	/*
	*/
	/*
		Procesamiento
	*/

	// Abrir el archivo de salida y comprobar que no hay problemas
	

	// Las grillas son 3, usando % se hace un bucle a traves de estas tres grillas.
	// Reserva de memoria para grillas
	for (int i = 0; i < 3; ++i) {
		grids[i] = allocate_grid_memory(grid_size);
	}
	// Rellenado de matrices
	grids[0] = initialize_grid(grids[0], grid_size, 20);
	grids[1] = initialize_grid(grids[1], grid_size, 0);
	grids[2] = initialize_grid(grids[2], grid_size, 0);
	
	// Crear hebras



	// Correr la primera iteracion y esperar con join


	// Correr todas las iteraciones que faltan y esperar con join



	// Escribir los resultados que se encuentran en grids[2] en un archivo



	
	return 0;
}

