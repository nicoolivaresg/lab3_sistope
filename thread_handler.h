/*
	HEADERS DE FUNCIONES PARA MANEJADOR DE HEBRAS
*/

#ifndef _THREAD_HANDLER_H
#define _THREAD_HANDLER_H

#include "util.h"
#include "wave_generator.h"
#include <pthread.h>

struct WaveGeneratorThread;

typedef struct WaveGeneratorThread{
	/*Agregar o eliminar datos necesarios para la hebra*/
	
	int id;			/* Identificador para la hebra que use esta estructura. */
	int grid_size;	/* Filas y columnas de la matriz de caracteres. */
	float *** matrix;	/* Puntero a la matriz en donde se deben posicionar las palabras. */
	pthread_t thread;	/* Hilo que se usa para crear la hebra. */
	pthread_mutex_t ** threadMutex;	/* Arreglo de mutex con tamaño de filas.*/

	
} WGThread;



#endif