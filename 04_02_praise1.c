#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define PRAISE "Вы - выдающаяся личность!"

int main()
{
  setlocale(0,"RUS");

  char name[40];

  printf("Как вас зовут? \n");
  scanf("%s", name);
  printf("Здравствуйте, %s. %s\n", name, PRAISE);
  printf("Ваше имя состоит и %zd символов и  занимает %zd ячеек памяти.\n", strlen(name), sizeof name);
  printf("Хвалебная фраза содержит %zd символов", strlen(PRAISE));
  printf("и занимает %zd ячеек памяти.\n", sizeof PRAISE);
  return 0;
}
