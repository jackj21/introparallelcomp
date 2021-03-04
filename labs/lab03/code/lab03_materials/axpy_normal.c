#include <stdlib.h> // for random number generation
#include <time.h> // for clock timing
#include <stdio.h> // for input/output
#include "vector.h"


int main(int argc, char *argv[]){

    // check that a command line argument specifying the dimension is present
    if(argc < 2){
        printf("WARNING: Missing one input argument. \n");
        printf("Run code as > executable_name dimension_of_test (filename_for_timing_data) \n");
        return 1;
    } 
    // argv[1] holds the dimension of the test vectors as a string
    // so use atoi function (part of stdlib.h) to change to an interger
    int dim = atoi(argv[1]);

    float a = 1.5;
    Vector x;
    Vector y;
    Vector z;

    // allocate the vectors and fill x and y with random numbers
    allocate(&x, dim);
    allocate(&y, dim);
    allocate(&z, dim);
    random_fill(&x);
    random_fill(&y);

    // number of runs, and declare timers
    int n_trials = 100; 
    clock_t beginning, ending;

    // --------do an axpy (z = a*x + y) in regular order----------
    beginning = clock();
    for(int i = 0; i < n_trials; ++i) {
        axpy(a, &x, &y, &z);
    }
    ending = clock();

    double secondsToRun = (double)(ending-beginning) / (double)CLOCKS_PER_SEC;
    double avgSecPerRunReg = secondsToRun/(double)n_trials;

    printf("%d, %17.15f\n", dim, avgSecPerRunReg);

    // cleanup
    deallocate(&x);
    deallocate(&y);
    deallocate(&z);

    return 0;
}
