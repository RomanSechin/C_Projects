#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
  setlocale(0,"RUS");

  int n;
  printf("Введите три целых числа:\n");
  scanf("%*d %*d %d", &n);
  printf("Последним целым числом было %d\n", n);
  return 0;
}
