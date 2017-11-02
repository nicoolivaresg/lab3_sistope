/*
	HEADERS DE FUNCIONES PARA CREADOR DE SOPA DE LETRAS (word_search_creator.H)
*/
#ifndef _WAVE_GENERATOR_H
#define _WAVE_GENERATOR_H

#include "util.h"
#include <unistd.h>

/**
 * Funcion que aloca la memoria necesaria para crear una matriz de tamaño
 * N x M, (Filas x columnas) y la retorna.
 * 
 * Entrada:
 *	N	- Puntero a un entero con la cantidad de filas de la matriz.
 *  M 	- Puntero a un entero con la cantidad de columnas de la matriz.
 * 
 * Salida: Matriz de tamaño N x M.
 */
float ** allocate_grid_memory(int * N);

/**
 * Funcion que recibe una matriz de caracteres y la rellena con el caracter
 * especial '@' para luego retornarla.
 * 
 * Entrada:
 *	grid  - Matriz de caracteres.
 *	N		- Puntero a un entero con la cantidad de filas de la matriz.
 *  M 		- Puntero a un entero con la cantidad de columnas de la matriz.
 * 
 * Salida: Matriz rellenada con el caracter especial '@'.
 */
float ** initialize_grid(float ** grid, int * N);

/**
 * Imprime una matriz de caracteres en la consola.
 * 
 * Entrada:
 *	grid - Matriz a imprimir en consola.
 *	N		- Puntero a un entero con la cantidad de filas de la matriz.
 *  M 		- Puntero a un entero con la cantidad de columnas de la matriz.
 */
void show_grid(float ** grid, int * N);



#endif