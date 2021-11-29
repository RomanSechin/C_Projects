#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define SIZE 40
#define LIM 5

char * s_gets(char * st, int n);
int main()
{
  setlocale(0,"RUS");
  char qwords[LIM][SIZE];
  char temp[SIZE];
  int i = 0;

  printf("������� %d ����, ������� ���������� � ����� �:\n", LIM);
  while(i < LIM && s_gets(temp, SIZE))
  {
    if(temp[0] != '�')
      printf("%s �� ���������� � ����� �!\n", temp);
    else
    {
      strcpy(qwords[i], temp);
      ++i;
    }
  }
  printf("������ �������� ����:\n");
  for(i = 0; i < LIM; ++i)
    puts(qwords[i]);
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
