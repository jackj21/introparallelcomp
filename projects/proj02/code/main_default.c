#include "grid.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * Main function that takes n, m_x, m_y, alpha, and T as
 * command line arguments to run various simulations.
 */ 
int main(int argc, char* argv[]) {
	if (argc != 6) {
		printf("Not enough arguments supplied.\n");
		return 1;
	}


	unsigned int n;
	unsigned int m_x;
	unsigned int m_y;
	float alpha;
	unsigned int T;

	sscanf(argv[1], "%d", &n);
	sscanf(argv[2], "%d", &m_x);
	sscanf(argv[3], "%d", &m_y);
	sscanf(argv[4], "%f", &alpha);
	sscanf(argv[5], "%d", &T);
	
	clock_t start_t, end_t;

	start_t = clock();
	simulate(T, n, n, m_x, m_y);
	end_t = clock();

	double total_t = (double)(end_t - start_t) / (double)CLOCKS_PER_SEC;
	
	printf("%d, %f\n", n, total_t);
}
