#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
  float salary;

  setlocale(0,"RUS");
  printf("\a������� �������� ����� �������� ��������:");
  printf("$_______\b\b\b\b\b\b\b");
  scanf("%f", &salary);
  printf("\n\t%.2f � ����� ������������� $%.2f � ���.", salary, salary * 12.0);
  printf("\r���!\n");

    return 0;
}
