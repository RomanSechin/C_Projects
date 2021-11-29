#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void trystat(void);
int main()
{
  setlocale(0,"RUS");

  int count;
  for( count = 1; count <= 3; ++count)
  {
    printf("The iteration %d:\n", count);
    trystat();
  }
  return 0;
}

void trystat(void)
{
  int fade = 1;
  static int stay = 1;

  printf("fade = %d and stay = %d\n", fade, stay++);
}
