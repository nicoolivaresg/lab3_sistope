#include <stdio.h>
#include <stdlib.h>

int main() {
	int i, j, k, H = 14, N = 128, T = 2000;
	float iterations = 10;
	int minutes;
	float seconds, realTime, totalTime = 0;
	float time1;
	FILE* input;
	FILE* output;
	FILE* speedup;
	FILE* efficiency;

	output = fopen("../matlab/times.csv", "w");
	speedup = fopen("../matlab/speedup.csv", "w");
	efficiency = fopen("../matlab/efficiency.csv", "w");

	for(j = 0; j <= 1; j++) {
		if(j == 0) N = 128;
		if(j == 1) N = 256;
		for(k = 0; k <= 2; k++) {
			if(k == 0) T = 2000;
			if(k == 1) T = 4000;
			if(k == 2) T = 8000;

			char filename[100];
			sprintf(filename, "times/time-%d-%d.txt", N, T);

			fprintf(output, "%d,%d", N, T);
			fprintf(speedup, "%d,%d", N, T);
			fprintf(efficiency, "%d,%d", N, T);
			input = fopen(filename, "r");
			for(i = 0; i < H; i++) {
				fscanf(input, " real %dm%fs", &minutes, &seconds);
				realTime = (float)minutes * 60.0 +  seconds;
				totalTime += realTime; /* Total execution time */
				realTime /= iterations;

				if(i == 0) {
					time1 = realTime;
				}
	
				fprintf(output, ",%f", realTime);
				fprintf(speedup, ",%f", time1/realTime);
				fprintf(efficiency, ",%f", time1/(realTime * (float)(i+1)));

				// Read other unused data.
				fscanf(input, " user %dm%fs", &minutes, &seconds);
				fscanf(input, " sys %dm%fs", &minutes, &seconds);
			}
			fprintf(output, "\n");
			fprintf(speedup, "\n");
			fprintf(efficiency, "\n");
		}
	}

	printf("Total script execution time = %f minutes\n", totalTime/60.0);

	fclose(output);
	fclose(speedup);
	fclose(efficiency);


	return 0;
}
