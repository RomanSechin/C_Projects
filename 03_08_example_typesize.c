#include <stdio.h>
#include <locale.h>

int main()
{
  setlocale(0,"RUS");
  printа("Тип short имеет размер %zd байтов.\n",sizeof(short));
  printf("Тип int имеет размер %zd байтов.\n",sizeof(int));
  printf("Тип char имеет размер %zd байтов.\n",sizeof(char));
  printf("Тип long имеет размер %zd байтов.\n",sizeof(long));
  printf("Тип long long имеет размер %zd байтов.\n",sizeof(long long));
  printf("Тип double имеет размер %zd байтов.\n",sizeof(double));
  printf("Тип long double имеет размер %zd байтов.\n",sizeof(long double));
  return 0;
}
