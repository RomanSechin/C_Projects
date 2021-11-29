#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
  setlocale(0,"RUS");
  float h;
  char name[40];
  printf("¬ведите ваш рост: ");
  scanf("%f", &h);
  printf("¬ведите ваше им€: ");
  scanf("%s", name);
  printf("%s, ваш рост %.1f.", name, h);
  return 0;
}
