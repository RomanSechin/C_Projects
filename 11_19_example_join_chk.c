#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define SIZE 30
#define BUGSIZE 13

char * s_gets(char * st, int n);

int main()
{
  setlocale(0,"RUS");
  char flower[SIZE];
  char addon[] = " ������ ��� ������ �������.";
  char bug[BUGSIZE];
  int available;
  puts("����� � ��� ������� ������?");
  s_gets(flower, SIZE);
  if((strlen(addon) + strlen(flower) + 1) <= SIZE)
    strcat(flower, addon);
  puts(flower);
  puts("����� � ��� ������� ���������?");
  s_gets(bug, BUGSIZE);
  available = BUGSIZE - strlen(bug) - 1;
  strncat(bug, addon, available);
  puts(bug);
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
