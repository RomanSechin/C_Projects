#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define CM_PER_FEET 30.48
#define CM_PER_INCH 2.54

int main()
{
  setlocale(0,"RUS");

  float height;
  int feet;
  float inch;
  printf("Введите высоту в сантиметрах(<=0 для выхода из прораммы): ");
  scanf("%f", &height);
  while(height > 0)
  {
    feet = height / CM_PER_FEET;
    inch = (height - feet * CM_PER_FEET)/CM_PER_INCH;
    printf("%.1f см = %d футов, %.1f дюймов\n" , height, feet, inch);
    printf("\nВведите высоту в сантиметрах(<=0 для выхода из прораммы): ");
    scanf("%f", &height);
  }
  printf("Работа завершена.\n");
  return 0;
}
