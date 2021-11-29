#include <stdio.h>
#include <stdlib.h>
#define n 12
#define N 10
int main(int argc, char ** argv)
{
    int p = 0, q = 0, t = 0, j = 0;
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
      {6, 1}};
    int id[N] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    printf("p q\t0 1 2 3 4 5 6 7 8 9\n");

    for(int i = 0; i < n; ++i)
    {
      p = arr[i][0];
      q = arr[i][1];
      if(id[p] == id[q]) continue;
      for(t = id[p], j = 0; j < N; ++j)
      {
        if(id[j] == t) id[j] = id[q];
      }
      printf("%d %d\t%d %d %d %d %d %d %d %d %d %d\n", p, q, id[0], id[1], id[2], id[3], id[4], id[5], id[6], id[7], id[8], id[9] );
    }

    return 0;
}
