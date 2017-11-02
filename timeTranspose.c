#include <stdio.h>
#include <stdlib.h>

int main() {
	int i, j, k, H = 14, N = 128, T = 2000;
	float iterations = 1;
	int minutes;
	float seconds, realTime, totalTime = 0;
	FILE* input;
	FILE* output;

	output = fopen("times.txt", "w");

	for(j = 0; j <= 2; j++) {
		if(j == 0) N = 128;
		if(j == 1) N = 256;
		if(j == 2) N = 512;
		for(k = 0; k <= 2; k++) {
			if(k == 0) T = 2000;
			if(k == 1) T = 4000;
			if(k == 2) T = 8000;

			char filename[100];
			sprintf(filename, "times/time-%d-%d.txt", N, T);

			fprintf(output, "N=%d,T=%d", N, T);
			input = fopen(filename, "r");
			for(i = 0; i < H; i++) {
				fscanf(input, " real %dm%fs", &minutes, &seconds);
				realTime = (float)minutes * 60.0 +  seconds;
				totalTime += realTime; /* Total execution time */
				realTime /= iterations;
				fprintf(output, ",%f", realTime);

				// Read other unused data.
				fscanf(input, " user %dm%fs", &minutes, &seconds);
				fscanf(input, " sys %dm%fs", &minutes, &seconds);
			}
			fprintf(output, "\n");
		}
	}

	printf("Total script execution time = %f minutes\n", totalTime/60.0);

	fclose(output);


	return 0;
}