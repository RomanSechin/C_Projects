#include <stdio.h>
#include <locale.h>

int main()
{
  setlocale(0,"RUS");
  char ch;
  while((ch = getchar()) != EOF)
  {
    putchar(ch);
  }
  return 0;
}
