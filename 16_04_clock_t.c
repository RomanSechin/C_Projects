#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

void wait(double sec)
{
  clock_t start = clock();
  clock_t finish;
  double diff = 0.0;
  do
  {
    finish = clock();
    diff = (double)(finish - start)/CLOCKS_PER_SEC;
  }
  while(diff < sec);
}


int main()
{
  setlocale(0,"RUS");

  double sec;
  printf("set the time in seconds:\n");
  while(scanf("%lf", &sec) != 1)
  {
    fflush(stdin);
    printf("set the time in seconds:\n");
    getchar();
  }
  clock_t st = clock();
  wait(sec);
  clock_t fn = clock();
  printf("function worked %f seconds.\n", difftime(fn, st)/1000);

  return 0;
}
