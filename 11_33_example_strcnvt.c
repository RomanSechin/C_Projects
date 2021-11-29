#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define LIM 30

char * s_gets(char * st, int n);
int main()
{
  setlocale(0,"RUS");

  char number[LIM];
  char * end;
  long value;

  puts("������� ����� (��� ������ ������ ��� ������ �� ���������):");
  while(s_gets(number, LIM) && number[0] != '\0')
  {
    value = strtol(number, &end, 10);//�� ��������� 10
    printf("���������� ����, ���������� �����: %ld, ��������� �� %s (%d)\n", value, end, *end);
    value = strtol(number,&end, 16);//�� ��������� 16
    printf("����������������� ����, ����������������� �����: %ld, ��������� �� %s (%d)\n", value, end, *end);
    puts("��������� �����:");
  }
    puts("��������� ���������.");
  return 0;
}

char * s_gets(char * st, int n)
{
  char * ret_val;
  int i = 0;

  ret_val = fgets(st, n, stdin);
  if(ret_val)
  {
    while(st[i] != '\n' && st[i] != '\0')
      ++i;
    if(st[i] == '\n')
      st[i] = '\0';
    else
      while(getchar() != '\n')
      continue;
  }
  return ret_val;
}
