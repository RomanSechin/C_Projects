#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <limits.h>
#include <string.h>

char * dec2hex(int a, char * tmp);
int main()
{
  setlocale(0,"RUS");
  int size =  CHAR_BIT * sizeof(int);
  char tmp[size];

  int a = 32;
  printf("%d(10) = %s(16)\n",a , dec2hex(a, tmp));
  return 0;
}

char * dec2hex(int a, char * tmp)
{
    int position = 0;
    {
     do
       int r = (a%16);
        if (r>9)
        {
           r += (int)'A'-10;
        }
        else
        {
            r += (int)'0';
        }
        tmp[position] = (char)r;
        ++position;
        a /= 16;
    }
    while(a);
    tmp[position] = '\0';
    tmp = strrev(tmp);
    return tmp;
}
