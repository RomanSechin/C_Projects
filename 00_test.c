#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
  setlocale(0,"RUS");
  printf("Привет, Мир!\n");
  return 0;
}
