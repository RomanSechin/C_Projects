#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
  setlocale(0,"RUS");

  int num;
  float float_num;
  printf("Input the number: \n");
  scanf("%d", &num);
  printf("%d\n", num);
  printf("%-4X", num);
  printf("\ninput the float number\n");
  scanf("%f", &float_num);
  printf("%10.3f\n", float_num);
  printf("%12e\n", float_num);
  printf("%-30s", "Abracadabra or cadabra.\n");
  return 0;
}
