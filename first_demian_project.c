#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
  setlocale(LC_ALL, "Rus");
  char * s = "������";

  int i;
  for( i = 1; i <= 5; ++i)
  {
      printf("%d: ���� ����� %s\n",i, s);
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
