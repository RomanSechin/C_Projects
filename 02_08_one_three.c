#include <stdio.h>
#include <stdlib.h>
void three()
{
  printf("three\n");
}

void two()
{
  printf("two\n");
  three();
}

void one_three()
{
  printf("one\n");
  two();
}

int main()
{
    printf("begin\n");
    one_three();
    printf("OK!\n");
    return 0;
}
