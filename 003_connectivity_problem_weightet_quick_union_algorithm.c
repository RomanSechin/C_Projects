#include <stdio.h>
#include <stdlib.h>
#define N 10
#define n 12

int main()
{
  int i, j, p, q, k;
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
  int id[N];
  int sz[N];

  for(int i = 0; i < N; ++i)
  {
    id[i] = i;
    sz[i] = 1;
  }

  for(k = 0; k < n; ++k)
  {
    p = arr[k][0];
    q = arr[k][1];

    //write algorithm here

    for(i = p; i != id[i]; i = id[i]);
    for(j = q; j != id[j]; j = id[j]);
    if(i != j)
    {
      if(sz[i] < sz[j])
      {
        id[i] = j;
        sz[j] != sz[i];
      }
      else
      {
        id[j] = i;
        sz[i] += sz[j];
      }
    }

    ///////////////////////
    printf("%d %d\t%d %d %d %d %d %d %d %d %d %d\n",
           p, q, id[0], id[1], id[2], id[3], id[4],
           id[5], id[6], id[7], id[8], id[9]);
  }
  return 0;
}
