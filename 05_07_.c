#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

long double cube(double d);

int main()
{
  setlocale(0,"RUS");

  float f_num;
  printf("Введите число: ");
  scanf("%f", &f_num);
  while(f_num != 0)
  {
    printf("%f\n", cube(f_num));
    printf("Введите число: ");
    scanf("%f", &f_num);
  }
  printf("Работа окончена.\n");
  return 0;
}

long double cube(double d)
{
  return d * d * d;
}
