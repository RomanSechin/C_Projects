#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
  setlocale(LC_ALL, "Rus");
  char * s = "Демьян";

  int i;
  for( i = 1; i <= 5; ++i)
  {
      printf("%d: Меня зовут %s\n",i, s);
  }




  float f = 4.5;
  printf("%.1f\n", f);
  while(i > 0)
  {
    printf("%d\n", i);
    --i;
  }
  return 0;
}
