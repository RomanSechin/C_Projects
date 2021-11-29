#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
  float salary;

  setlocale(0,"RUS");
  printf("\a¬ведите желаемую сумму мес€чной зарплаты:");
  printf("$_______\b\b\b\b\b\b\b");
  scanf("%f", &salary);
  printf("\n\t%.2f в мес€ц соответствует $%.2f в год.", salary, salary * 12.0);
  printf("\rќго!\n");

    return 0;
}
