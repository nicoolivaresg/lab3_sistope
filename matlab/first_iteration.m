function [grids] = first_iteration(N)
	int t = 1;
	for (i = 0; i < thread->rows; ++i)
	{
		row = thread->startingRow + i;
		for (col = 0; col < N; ++col)
		{
			if(row == 0 || col == 0 || row == N || col == N ) {
				grids(t,row,col) = 0;
			} else {
				grids(t,row,col) = schroendinger(row, col, t);
			}
		}
	}
end
	
