
#include <stdio.h>
#include <stdlib.h>

//Mat Mat Multiply

#define N 2000


int main()
{

  int r1, c1, r2, c2, c, d, k, sum = 0;
  
  int **first = malloc(N*sizeof(int*));
  
  int **second = malloc(N*sizeof(int*));

  int **multiply = malloc(N*sizeof(int*));

  
 
  for(int i=0;i< N;i++){

    first[i] = malloc(N*sizeof(int));
    second[i] = malloc(N*sizeof(int));
    multiply[i] = malloc(N*sizeof(int));

  }
  

  


  printf("Initializing Matrices\n");

  for (c = 0; c < N; c++)
    for (d = 0; d < N; d++)
      first[c][d] = 1;
      //scanf("%d", &first[c][d]);



    for (c = 0; c < N; c++)
      for (d = 0; d < N; d++)
          second[c][d] = 2;

    for (c = 0; c < N; c++) {
      for (d = 0; d < N; d++) {
        for (k = 0; k < N; k++) {
          sum = sum + first[c][k]*second[k][d];
        }

        multiply[c][d] = sum;
        sum = 0;
      }
    }
/*
    printf("Product of the matrices:\n");

    for (c = 0; c < N; c++) {
      for (d = 0; d < N; d++)
        printf("%d\t", multiply[c][d]);

      printf("\n");
    }
 */


//free the memory

printf("Done\n");

  return 0;
}
