#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define PRAISE "�� - ���������� ��������!"

int main()
{
  setlocale(0,"RUS");

  char name[40];

  printf("��� ��� �����? \n");
  scanf("%s", name);
  printf("������������, %s. %s\n", name, PRAISE);
  printf("���� ��� ������� � %zd �������� �  �������� %zd ����� ������.\n", strlen(name), sizeof name);
  printf("��������� ����� �������� %zd ��������", strlen(PRAISE));
  printf("� �������� %zd ����� ������.\n", sizeof PRAISE);
  return 0;
}
