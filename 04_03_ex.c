#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
  setlocale(0,"RUS");
  float f;
  printf("Input the float number: ");
  scanf("%f", &f);
  printf("%.4f %.4e", f, f);
  return 0;
}
