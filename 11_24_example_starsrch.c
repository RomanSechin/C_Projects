#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define LISTSIZE 6

int main()
{
  setlocale(0,"RUS");
  const char* list[LISTSIZE] =
  {
    "����������", "��������",
    "�����������","���������",
    "��������","����������"
  };
  int count = 0;
  int i;

  for(i = 0; i < LISTSIZE; ++i)
    if(strncmp(list[i], "�����", 5) == 0)
  {
    printf("�������: %s\n",  list[i]);
    ++count;
  }
  printf("���������� ���� � ������,"
         " ������������ � �����: %d\n", count);
  return 0;
}
