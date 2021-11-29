#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
  setlocale(0,"RUS");

  printf("«десь один из способов вывода ");
  printf("длинной строки.\n");
  printf("¬от второй способ вывода \
длинной строки.\n");
  printf("ј вот самый новый способ вывода "
         "длинной строки.\n");

  return 0;
}
