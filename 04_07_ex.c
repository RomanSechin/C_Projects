#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <float.h>

int main()
{
  setlocale(0,"RUS");
  double first = 1.0/3.0;
  float second = 1.0/3.0;

  printf("%-18.4f %-18.4f\n", first, second);
  printf("%-18.12f %-18.12f\n", first, second);
  printf("%.16f %.16f\n", first, second);
  printf("FLT_DIG = %d DBL_DIG = %d", FLT_DIG, DBL_DIG);
  return 0;
}
