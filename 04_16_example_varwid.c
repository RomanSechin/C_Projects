#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(0,"RUS");
  unsigned width, precision;
  int number = 256;
  double weight = 242.5;

  printf("������� ������ ����:\n");
  scanf("%d", &width);

  printf("�������� �����: %*d:\n", width, number);
  printf("������ ������� ������ � ��������:\n");
  scanf("%d %d", &width, &precision);
  printf("��� = %*.*f\n", width, precision, weight);
  printf("������!\n");

  return 0;
}
