#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
  setlocale(0,"RUS");
  int i = 0;
  int n;
  unsigned long long sum = 0;

  printf("Введите число: ");
  scanf("%d", &n);
  while(n > 0)
  {
    while(i <= n)
    {
      sum += i * i;
      ++i;
    }
    printf("%d\n", sum);
    sum = 0;
    i = 0;
    printf("\nВведите число (<= 0 конец работы): ");
    scanf("%d", &n);
  }
  printf("Конец работы.");
  return 0;
}
