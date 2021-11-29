#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define DAYS_PER_WEEK 7

void print_answer(int days);

int main()
{
  setlocale(0,"RUS");
  int days;
  printf("������� ���������� ����: ");
  int n_scan = scanf("%d", &days);
  while(n_scan == 1 && days > 0)
  {
    print_answer(days);
    printf("\n������� ���������� ����: ");
    n_scan = scanf("%d", &days);
  }
  return 0;
}

void print_answer(int days)
{
  printf("%d ���� ���������� %d ������ � %d ���.", days, days / DAYS_PER_WEEK, days % DAYS_PER_WEEK);
}
