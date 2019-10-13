
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int r1, c1, r2, c2, c, d, k, sum = 0;
  int first[10][10], second[10][10], multiply[10][10];

  printf("Enter number of rows and columns of first matrix\n");
  scanf("%d%d", &r1, &c1);
  printf("Enter elements of first matrix\n");

  for (c = 0; c < r1; c++)
    for (d = 0; d < c1; d++)
      scanf("%d", &first[c][d]);

  printf("Enter number of rows and columns of second matrix\n");
  scanf("%d%d", &r2, &c2);

  if (c1 != r2)
    printf("The matrices can't be multiplied with each other.\n");
  else
  {
    printf("Enter elements of second matrix\n");

    for (c = 0; c < r2; c++)
      for (d = 0; d < c2; d++)
        scanf("%d", &second[c][d]);

    for (c = 0; c < r1; c++) {
      for (d = 0; d < c2; d++) {
        for (k = 0; k < c1      ; k++) {
          sum = sum + first[c][k]*second[k][d];
        }

        multiply[c][d] = sum;
        sum = 0;
      }
    }

    printf("Product of the matrices:\n");

    for (c = 0; c < r1; c++) {
      for (d = 0; d < c2; d++)
        printf("%d\t", multiply[c][d]);

      printf("\n");
    }
  }

  return 0;
}
