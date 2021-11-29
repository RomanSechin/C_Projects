#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
  setlocale(0,"RUS");
  int ch;
  /*printf("¬ведите код символа (0..255):\n");
  scanf("%d", &ch);
  printf("%d соответствует символу %c", ch, ch);*/
  for(int i = 0; i < 256; ++i)
  {
    printf("%d соответствует символу %c\n", i, i);
  }
  return 0;
}
