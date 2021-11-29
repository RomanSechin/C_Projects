#include <stdio.h>
#include <stdlib.h>
#define n 12
#define N 10
int main(int argc, char ** argv)
{
  int p = 0, q = 0, i = 0,
   j = 0, k = 0;
  int arr[n][2] = {
    {3, 4},
    {4, 9},
    {8, 0},
    {2, 3},
    {5, 6},
    {2, 9},
    {5, 9},
    {7, 3},
    {4, 8},
    {5, 6},
    {0, 2},
    {6, 1}
  };
  int id[N] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  printf("p q\t0 1 2 3 4 5 6 7 8 9\n\n");

  ////////////////////////////
  for(k = 0; k < n; ++k)
  {
    p = arr[k][0];
    q = arr[k][1];
    for(i = p; i != id[i]; i = id[i])
      id[i] = id[id[i]];
    for(j = q; j != id[j]; j = id[j])
      id[j] = id[id[j]];

    ////////////////////////////
    printf("%d %d\t%d %d %d %d %d %d %d %d %d %d\n", p, q, id[0], id[1], id[2], id[3], id[4], id[5], id[6], id[7], id[8], id[9] );
  }

  return 0;
}
