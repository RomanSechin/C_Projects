#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
  setlocale(0,"RUS");

  int cm;

  printf("������� ��� ���� � ��: ");
  scanf("%d", &cm);
  printf("��� ���� � ������: %f\n", cm / 2.54);

  return 0;
}
