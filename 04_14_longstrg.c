#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
  setlocale(0,"RUS");

  printf("����� ���� �� �������� ������ ");
  printf("������� ������.\n");
  printf("��� ������ ������ ������ \
������� ������.\n");
  printf("� ��� ����� ����� ������ ������ "
         "������� ������.\n");

  return 0;
}
