#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
  setlocale(0,"RUS");

  int age;

  printf("������� ��� �������: ");
  scanf("%d", &age);
  printf("\n�� ������� %Ld ������", (long)(age * 3.56E7));

  return 0;
}
