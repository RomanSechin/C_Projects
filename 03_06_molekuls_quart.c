#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
  setlocale(0,"RUS");
  double mass_mol = 3.0E-23;
  double mass_qt = 950;
  float count_of_quarts;
  double molecules;
  printf("Введите количество кварт воды: ");
  scanf("%f", &count_of_quarts);
  molecules = count_of_quarts * mass_qt / mass_mol;
  printf("\nВ этом объеме %e молекул.\n", molecules);

  return 0;
}
