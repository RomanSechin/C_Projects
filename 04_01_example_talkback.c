#include <stdio.h>
#include <string.h>
#include <locale.h>
#define DENSITY 62.4

int main()
{
  setlocale(0, "RUS");
  float weight, volume;
  int size, letters;
  char name[40];

  printf("Здравствуйте, как вас зовут?\n");
  scanf("%s", name);
  printf("\n%s, cколько вы весите в фунтах?\n", name);
  scanf("%f", &weight);
  size = sizeof name;
  letters = strlen(name);
  volume = weight / DENSITY;

  printf("Хорошо, %s, ваш объем составляет %2.2f кубических футов.\n", name, volume);
  printf("К тому же ваше имя состоит из %d букв,\n", letters);
  printf("и мы располагаем %d байтами для его хранения.\n", size);
  return 0;
}
