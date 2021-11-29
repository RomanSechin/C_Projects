#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
  setlocale(0,"RUS");
  char name[40];
  char second_name[40];

  printf("Input your name and second name: ");
  scanf("%s %s", name, second_name);

  printf("\nHello, %s %s", second_name, name);

  return 0;
}
