/*
	IMPLEMENTACION DE FUNCIONES PARA EL MANEJADOR DE HEBRAS (thread_handler.h)
*/

#include "thread_handler.h"

void WGThread_init(WGThread* thread, int id, int gridSize, int rows, int startingRow, int iterations)
{
	thread->id = id;
	thread->gridSize = gridSize;
	thread->rows = rows;
	thread->startingRow = rows;
	thread->iterationsLeft = iterations-1;
}

float schroendinger(int row, int col, int t) {
	return grids[(t-1) % 3][row][col] + (constantGlobal/2)*(grids[(t-1) % 3][row-1][col] + grids[(t-1) % 3][row+1][col] + 
		grids[(t-1) % 3][row][col-1] + grids[(t-1) % 3][row][col+1] - 4 * grids[(t-1) % 3][row][col]);
}

void* first_iteration(void* args)
{
	int i;
	WGThread* thread = (WGThread*) args;
	int t = 1;
	for (i = 0; i < thread->rows; ++i)
	{
		int row = thread->startingRow + i;
		for (int col = 0; col < thread->gridSize; ++col)
		{
			if(row == 0 || col == 0 || row == thread->gridSize - 1 || col == thread->gridSize - 1) {
				grids[t][row][col] = 0;
			} else {
				grids[t][row][col] = schroendinger(row, col, t);
			}
		}
	}
}

void* iterations(void* args)
{
	int i;
	WGThread* thread = (WGThread*) args;
	int t = 2;
	while(thread->iterationsLeft--) {
		for (i = 0; i < thread->rows; ++i)
		{
			int row = thread->startingRow + i;
			for (int col = 0; col < thread->gridSize; ++col)
			{
				if(row == 0 || col == 0 || row == thread->gridSize - 1 || col == thread->gridSize - 1) {
					grids[t][row][col] = 0;
				} else {
					grids[t][row][col] = 2*schroendinger(row, col, t) - grids[(t-2) % 3][row][col];
				}
			}
		}

		pthread_barrier_wait(&barrier);
		t = (t+1) % 3;
	}
}
