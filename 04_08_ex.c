#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
  setlocale(0,"RUS");
  float miles;
  float gallons;
  float liter_per_hundred;


  printf("������ ���������� ����������� ���� � ���������� �������� �������\n");
  scanf("%f %f", &miles, &gallons);
  liter_per_hundred = 100 * (gallons * 3.785) / (miles * 1.609);


  printf("���� �� �������� %.1f ���������� � ��������� %.1f ������ �������, �� ��� ������ %.1f ������ �� 100 ����������.\n", miles * 1.609, gallons * 3.785, liter_per_hundred);
  return 0;
}
