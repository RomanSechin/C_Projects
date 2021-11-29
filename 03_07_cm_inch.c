#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
  setlocale(0,"RUS");

  int cm;

  printf("Введите ваш рост в см: ");
  scanf("%d", &cm);
  printf("Ваш рост в дюймах: %f\n", cm / 2.54);

  return 0;
}
