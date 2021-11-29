#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define CM_PER_FEET 30.48
#define CM_PER_INCH 2.54

int main()
{
  setlocale(0,"RUS");

  float height;
  int feet;
  float inch;
  printf("������� ������ � �����������(<=0 ��� ������ �� ��������): ");
  scanf("%f", &height);
  while(height > 0)
  {
    feet = height / CM_PER_FEET;
    inch = (height - feet * CM_PER_FEET)/CM_PER_INCH;
    printf("%.1f �� = %d �����, %.1f ������\n" , height, feet, inch);
    printf("\n������� ������ � �����������(<=0 ��� ������ �� ��������): ");
    scanf("%f", &height);
  }
  printf("������ ���������.\n");
  return 0;
}
