#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
  setlocale(0,"RUS");
  float cups;
    printf("Введите количество чашек: ");
    scanf("%f", &cups);
    printf("Это %f пинт, %f унций, %f столовых ложек и %f чайных ложек.", cups*2, cups/8, cups/16, cups/48);
    return 0;
}
