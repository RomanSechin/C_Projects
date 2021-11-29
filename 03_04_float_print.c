#include <stdio.h>
#include <locale.h>

int main()
{
  setlocale(0,"RUS");
  float f = 0.0;
  printf("Введите значение с плавающей запятой: ");
  scanf("%f", &f);
  printf("Запись с фиксированной запятой: %f\n", f);
  printf("Экспоненциальная форма записи: %e\n", f);
  printf("Двоично-экспоненциальное представление: %a\n", f);

  return 0;
}
