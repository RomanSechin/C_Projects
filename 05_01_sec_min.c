#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define MIN_IN_HOUR 60

int main()
{
  setlocale(0,"RUS");
  int minutes = 0;
  do
  {
    printf("������� ���������� �����: ");
    scanf("%d", &minutes);
    printf("� %d ������� %d ����� %d �����\n\n", minutes, minutes / MIN_IN_HOUR, minutes % MIN_IN_HOUR);
  }
  while(minutes > 0)
;
  return 0;
}
