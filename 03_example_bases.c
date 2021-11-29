#include <stdio.h>

int main()
{
  int x = 100;
  printf("decimal = %d; octal = %o; hexadecimal = %x\n", x, x, x);
  printf("decimal = %d; octal = %#o; hexadecimal = %#x\n", x, x, x);
  return 0;
}
