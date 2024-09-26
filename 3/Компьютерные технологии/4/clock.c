#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char* argv[])
{
    struct timespec start, stop;
    double res;

    clock_gettime(CLOCK_MONOTONIC, &start);

    system(argv[1]);

    clock_gettime(CLOCK_MONOTONIC, &stop);

    res = (stop.tv_sec - start.tv_sec) + (stop.tv_nsec - start.tv_nsec) / (double)(1000000000);

    printf("res: %lg\n", res);

    return 0;
}
