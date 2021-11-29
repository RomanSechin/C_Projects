#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void print10(int);
int main()
{
  setlocale(0,"RUS");
  int digit;
  int n_scan = 0;
  do
  {
    printf("¬ведите число: ");
    n_scan = scanf("%d",&digit);
    print10(digit);
  }
  while(n_scan == 1);
  return 0;
}

void print10(int n)
{
  for(int i = 0; i <= 10; ++i)
    printf("%d\n", n + i);
}
