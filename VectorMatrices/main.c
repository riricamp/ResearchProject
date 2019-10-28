
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
//Mat Mat Multiply

//sudo perf stat -e task-clock,cycles,instructions,cache-references,cache-misses

#define N 2000


int main()
{

  int r1, c1, r2, c2, c, d, k, sum = 0;

  int *first = malloc(N*N*sizeof(int));

  int *second = malloc(N*N*sizeof(int));

  int *multiply = malloc(N*N*sizeof(int));


  printf("Initializing Matrices\n");


  #pragma omp parallel shared(first, second, multiply) private(c,d,k) 
  {
printf("Thread rank: %d\n", omp_get_thread_num());
  #pragma omp for
  for (c = 0; c < N; c++)
    for (d = 0; d < N; d++)
      first[c*N +d] = 1;
      //scanf("%d", &first[c][d]);
  #pragma omp  for
  for (c = 0; c < N; c++)
    for (d = 0; d < N; d++)
      second[c*N +d] = 2;

  #pragma omp for
  for (c = 0; c < N; c++) {

    for (d = 0; d < N; d++) {
      multiply[c*N+d] = 0;
      //sum = 0;
      for (k = 0; k < N; k++) {
        multiply[c*N+d] = multiply[c*N+d] + first[c*N+k]*second[k*N+d];
      }

      //multiply[c*N+d] = sum;

    }
  }

}
/*
    printf("Product of the matrices:\n");

    for (c = 0; c < N; c++) {
      for (d = 0; d < N; d++)
        printf("%d\t", multiply[c*N+d]);

      printf("\n");
    }
*/


//free the memory

printf("Done\n");

  return 0;
}
