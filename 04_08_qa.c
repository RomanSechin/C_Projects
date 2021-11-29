#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
  setlocale(0,"RUS");
  char s[40
  ];
  int n;
  scanf("%*s %d", &n);
  printf("%s %d\n", s, n);
  printf("Тип double состоит из %zd байтов..\n", sizeof(double));
  return 0;
}
