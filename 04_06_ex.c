#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main()
{
  setlocale(0,"RUS");
  char name[40];
  char second_name[40];

  printf("¬ведите ваши им€ и фамилию:\n");
  scanf("%s %s", name, second_name);
  printf("%*d %*d\n", strlen(name), strlen(name), strlen(second_name), strlen(second_name));
  printf("%-*d %-*d\n", strlen(name), strlen(name), strlen(second_name), strlen(second_name));
  return 0;
}
