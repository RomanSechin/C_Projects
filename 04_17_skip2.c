#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
  setlocale(0,"RUS");

  int n;
  printf("������� ��� ����� �����:\n");
  scanf("%*d %*d %d", &n);
  printf("��������� ����� ������ ���� %d\n", n);
  return 0;
}
