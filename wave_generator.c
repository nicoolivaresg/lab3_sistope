#include "wave_generator.h"
/*
	IMPLEMENTACIÓN DE FUNCIONES GENERADOR DE OLA (wave_generator.h)
*/


float ** allocate_grid_memory(int * N){
	float ** newgrid = malloc(	(*N) * sizeof(char*) );
	int i = 0;
	for (i = 0; i < (*N); i++)
	{
		newgrid[i] = malloc( (*N) * sizeof(char) );
	}
	return newgrid;
}


float ** initialize_grid(float ** grid, int * N){
	int i,j;
	for (i = 0; i < (*N); i++)
	{
		for (j = 0; j < (*N); j++){
			grid[i][j] = 0;
		}
	}
	return grid;
}

void show_grid(float ** grid, int * N){
	int i,j;
	for (i = 0; i < (*N); i++)
	{
		for (j = 0; j < (*N); j++){
			printf("%.3f ", grid[i][j]);
		}
		printf("\n");
	}
}


