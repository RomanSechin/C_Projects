#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
  setlocale(0,"RUS");
  int ch;
  /*printf("������� ��� ������� (0..255):\n");
  scanf("%d", &ch);
  printf("%d ������������� ������� %c", ch, ch);*/
  for(int i = 0; i < 256; ++i)
  {
    printf("%d ������������� ������� %c\n", i, i);
  }
  return 0;
}
