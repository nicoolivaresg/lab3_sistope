/*
	HEADERS DE FUNCIONES PARA CREADOR DE SOPA DE LETRAS (word_search_creator.H)
*/
#ifndef _WAVE_GENERATOR_H
#define _WAVE_GENERATOR_H

#include "util.h"
#include <unistd.h>

/**
 * Funcion que aloca la memoria necesaria para crear una matriz de tamaño
 * N x N, (Filas x columnas) y la retorna.
 * 
 * Entrada:
 *	N	- Numero entero con el tamaño de la matriz.
 * 
 * Salida: Matriz de tamaño N x N.
 */
float ** allocate_grid_memory(int N);

/**
 * Funcion que recibe una matriz de flotantes y la rellena con 0s y con
 * el valor H en las posiciones que corresponda para simular una onda
 * cuadrada en el centro de la grilla.
 * 
 * Entrada:
 *	grid  - Puntero a la matriz de flotantes.
 *	N	- Numero entero con el tamaño de la matriz.
 *	H 	- Valor que toma la onda en la grilla.
 * 
 * Salida: Matriz rellenada con 0s o H donde corresponda.
 */
float** initialize_grid(float ** grid, int N, int H);

/**
 * Imprime una matriz de flotantes en la consola.
 * 
 * Entrada:
 *	grid - Matriz a imprimir en consola.
 *	N	- Numero entero con el tamaño de la matriz.
 */
void show_grid(float ** grid, int N);

#endif