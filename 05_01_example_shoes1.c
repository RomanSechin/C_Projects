#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define ADJUST 7.31

int main()
{
  setlocale(0,"RUS");
  const double SCALE = 0.333;
  double shoe, foot;
  shoe = 10.5;
  foot = SCALE * shoe + ADJUST;

  printf("������ ����� (�������)   ����� ������(inch) ����� ������(sm)\n");
  printf("%10.1f %20.2f ������ %20.2f �����������\n", shoe, foot, foot * 2.54);

  return 0;
}
