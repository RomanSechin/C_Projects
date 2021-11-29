#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define SQUARES 64

int main()
{
  setlocale(0,"RUS");
  const double CROP = 2E16;
  double current, total;
  int count = 1;
  printf("�������   ���������     �����     ");
  printf("   %% �� \n");
  printf("           ����       ����    ");
         printf(" �������� ������\n");
  total = current = 1.0;
  printf("%4d %13.2e %12.2e %12.2e\n", count, current, total, total/CROP);
  while(count < SQUARES)
  {
    ++count;
    current *= 2.0;
    total += current;
    printf("%4d %13.2e %12.2e %12.2e\n", count, current, total, total/CROP);
  }
  printf("��� � ��!\n");
  return 0;
}
