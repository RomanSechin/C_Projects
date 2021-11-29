#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main()
{
  setlocale(0,"RUS");
  char name[40];
  printf("Input your name: ");
  scanf("%s", name);

  printf("\"%s\"\n", name);
  printf("\"%20s\"\n", name);
  printf("\"%-20s\"\n", name);
  printf("\"%*s\"\n",strlen(name) + 3, name);
  return 0;
}
