#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define B "booboo"
#define X 10

int main()
{
  setlocale(0,"RUS");

  int age;

  char name[10];
  int xp;
  printf("������� ��� ���.");
  scanf("%s", name);
  printf("������, %s, � ������� ��� ���?\n", name);
  scanf("%d", &age);
  xp = age + X;
  printf("�������, %s! ��� ������ ����, �� ������� ����, %d.\n", B, xp);

  return 0;
}
