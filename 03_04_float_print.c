#include <stdio.h>
#include <locale.h>

int main()
{
  setlocale(0,"RUS");
  float f = 0.0;
  printf("������� �������� � ��������� �������: ");
  scanf("%f", &f);
  printf("������ � ������������� �������: %f\n", f);
  printf("���������������� ����� ������: %e\n", f);
  printf("�������-���������������� �������������: %a\n", f);

  return 0;
}
