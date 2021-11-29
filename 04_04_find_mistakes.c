#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define B "booboo"
#define X 10

int main()
{
  setlocale(0,"RUS");

  int age;

  char name[10];
  int xp;
  printf("Введите своё имя.");
  scanf("%s", name);
  printf("Хорошо, %s, а сколько вам лет?\n", name);
  scanf("%d", &age);
  xp = age + X;
  printf("Неужели, %s! Вам должно быть, по меньшей мере, %d.\n", B, xp);

  return 0;
}
