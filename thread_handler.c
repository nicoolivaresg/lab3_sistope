/*
	IMPLEMENTACION DE FUNCIONES PARA EL MANEJADOR DE HEBRAS (thread_handler.h)
*/

#include "thread_handler.h"

void WGThread_init(WGThread* thread, int id, int gridSize, int rows, int startingRow, int iterations)
{
	thread->id = id;
	thread->gridSize = gridSize;
	thread->rows = rows;
	thread->startingRow = startingRow;
	thread->iterationsLeft = iterations-1;
}

float schroendinger(int row, int col, int t) {
	return grids[mod((t-1), 3)][row][col] + (constantGlobal/2)*(grids[mod((t-1), 3)][row-1][col] + grids[mod((t-1), 3)][row+1][col] + 
		grids[mod((t-1), 3)][row][col-1] + grids[mod((t-1), 3)][row][col+1] - 4 * grids[mod((t-1), 3)][row][col]);
}

void* first_iteration(void* args)
{
	int i, col, row;
	WGThread* thread = (WGThread*) args;
	//printf("id:%d gridSize:%d rows:%d startingRow:%d iterations%d\n", thread->id, thread->gridSize, thread->rows, thread->startingRow, thread->iterationsLeft);
	int t = 1;
	for (i = 0; i < thread->rows; ++i)
	{
		row = thread->startingRow + i;
		for (col = 0; col < thread->gridSize; ++col)
		{
			if(row == 0 || col == 0 || row == thread->gridSize - 1 || col == thread->gridSize - 1) {
				grids[t][row][col] = 0;
			} else {
				grids[t][row][col] = schroendinger(row, col, t);
			}
		}
	}
}

void* other_iterations(void* args)
{
	int i, col, row;
	WGThread* thread = (WGThread*) args;
	int t = 2;
	while(thread->iterationsLeft--) {
		for (i = 0; i < thread->rows; ++i)
		{
			row = thread->startingRow + i;
			for (col = 0; col < thread->gridSize; ++col)
			{
				if(row == 0 || col == 0 || row == thread->gridSize - 1 || col == thread->gridSize - 1) {
					grids[t][row][col] = 0;
				} else {
					grids[t][row][col] = 2*schroendinger(row, col, t) - grids[mod((t-2), 3)][row][col];
				}
			}
		}

		pthread_barrier_wait(&barrier);
		t = (t+1) % 3;
	}
}
