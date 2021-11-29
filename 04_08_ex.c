#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
  setlocale(0,"RUS");
  float miles;
  float gallons;
  float liter_per_hundred;


  printf("Введие количество преодолённый миль и количество галлонов бензина\n");
  scanf("%f %f", &miles, &gallons);
  liter_per_hundred = 100 * (gallons * 3.785) / (miles * 1.609);


  printf("Если вы проехали %.1f километров и истратили %.1f литров бензина, то ваш расход %.1f литров на 100 километров.\n", miles * 1.609, gallons * 3.785, liter_per_hundred);
  return 0;
}
