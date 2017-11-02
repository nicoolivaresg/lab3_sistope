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
	int gridSize;	/* Filas y columnas de la matriz de caracteres. */
	int rows;		/* Filas que debe calcular este hilo. */
	int startingRow;/* Fila en la que debe empezar este hilo. */
	int iterationsLeft;	/* Las iteraciones que le falta ejecutar al hilo, se inicializa
					con iterations - 1 porque la primer iteracion se realiza aparte. */
	pthread_t thread;	/* Hilo que se usa para crear la hebra. */

	
} WGThread;

/**
 * Funcion que inicializa una estructura WGThread con los valores especificiados en sus parametros.
 *
 * Entrada:
 *	thread 	- Puntero a un WGThread, estructura en donde se inicializaran los datos.
 *	id 		- Identificador del hilo que se crea.
 *	gridSize- Tamaño de la grilla que se usa (variable global grids).
 *	rows	- Filas que tiene que evaluar este hilo.
 *	startingRow - Fila inicial de este hilo.
 *	iterations 	- Iteraciones que debe realizar este hilo.
 */
void WGThread_init(WGThread* thread, int id, int gridSize, int rows, int startingRow, int iterations);

/**
 * Evalua la ecuacion de schoendinger para la primera iteracion, si se quiere usar para las otras
 * iteraciones, se debe multiplicar el resultado que entrega esta funcion por 2 y restar el valor
 * que tenia la grilla hace dos iteraciones en la misma posicion [row][col].
 *
 * Entrada:
 * 	row - Fila en la que se realiza la evaluacion.
 * 	col - Columna en la que se realiza la evaluacion.
 * 	t 	- Tiempo en el que se evalua la funcion (para simplificar; 0, 1 o 2).
 *
 * Salida: Valor obtenido al evaluar la ecuacion de Schroendinger.
 */
float schroendinger(int row, int col, int t);

/**
 * Funcion que se usa con pthread_create para crear un hilo, se le debe entregar como
 * parametro un puntero a una estructura WSThread inicializada.
 *
 * Realiza la primera iteracion de la ecuacion de Schroendinger.
 * 
 * Entrada:
 *	args - Puntero a estructura WGThread.
 */
void* first_iteration(void* args);

/**
 * Funcion que se usa con pthread_create para crear un hilo, se le debe entregar como
 * parametro un puntero a una estructura WSThread inicializada.
 *
 * Realiza el caso general de las iteraciones de la ecuacion de Schroendinger.
 * 
 * Entrada:
 *	args - Puntero a estructura WGThread.
 */
void* other_iterations(void* args);


#endif