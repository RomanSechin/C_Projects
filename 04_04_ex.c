#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
  setlocale(0,"RUS");
  float h;
  char name[40];
  printf("������� ��� ����: ");
  scanf("%f", &h);
  printf("������� ���� ���: ");
  scanf("%s", name);
  printf("%s, ��� ���� %.1f.", name, h);
  return 0;
}
