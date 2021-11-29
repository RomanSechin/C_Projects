#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define BOOK "Война и мир"

int main()
{
  setlocale(0,"RUS");
  float cost = 12.99;
  float percent = 80.0;

  printf("Данный экземпляр книги %s стоит $%.2f\n"
         "Это %.0f\% от цены в прайс-листе.", BOOK, cost, percent);
  return 0;
}
