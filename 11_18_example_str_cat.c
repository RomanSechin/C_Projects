#include <stdio.h>
#include <string.h>
#include <locale.h>
#define SIZE 80
char * s_gets(char * st, int n);

int main()
{
  setlocale(0,"RUS");
  char flower[SIZE];
  char addon[] = " ������ ��� ������ �������.";
  puts("����� � ��� ������� ������?");
  if(s_gets(flower, SIZE))
  {
    strcat(flower, addon);
    puts(flower);
    puts(addon);
  }
  else
    puts("��������� ����� �����!");
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
    if(st[i]  == '\n')
      st[i] = '\0';
    else //��������� ������� words[i] == '\0'
      while(getchar() != '\n')
      continue;
  }
  return ret_val;
}
