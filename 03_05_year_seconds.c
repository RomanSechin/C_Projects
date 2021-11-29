#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
  setlocale(0,"RUS");

  int age;

  printf("Введите ваш возраст: ");
  scanf("%d", &age);
  printf("\nВы прожили %Ld секунд", (long)(age * 3.56E7));

  return 0;
}
