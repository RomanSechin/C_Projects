#include <stdio.h>
#include <string.h>
#include <locale.h>
#define DENSITY 62.4

int main()
{
  setlocale(0, "RUS");
  float weight, volume;
  int size, letters;
  char name[40];

  printf("������������, ��� ��� �����?\n");
  scanf("%s", name);
  printf("\n%s, c������ �� ������ � ������?\n", name);
  scanf("%f", &weight);
  size = sizeof name;
  letters = strlen(name);
  volume = weight / DENSITY;

  printf("������, %s, ��� ����� ���������� %2.2f ���������� �����.\n", name, volume);
  printf("� ���� �� ���� ��� ������� �� %d ����,\n", letters);
  printf("� �� ����������� %d ������� ��� ��� ��������.\n", size);
  return 0;
}
