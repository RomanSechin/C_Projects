#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define BOOK "����� � ���"

int main()
{
  setlocale(0,"RUS");
  float cost = 12.99;
  float percent = 80.0;

  printf("������ ��������� ����� %s ����� $%.2f\n"
         "��� %.0f\% �� ���� � �����-�����.", BOOK, cost, percent);
  return 0;
}
