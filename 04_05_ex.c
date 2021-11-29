#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
  setlocale(0,"RUS");

  float v, file_size;
  printf("¬ведите скорость загрузки в мегабитах в секунду и размер файла в мегабайтах:\n");
  scanf("%f %f", &v, &file_size);
  printf("ѕри скорости загрузки %.2f мегабит в секунду файл размером %.2f мегебайт загружаетс€ %.2f секунд(ы).\n",v, file_size, 8*file_size/v);
  return 0;
}
