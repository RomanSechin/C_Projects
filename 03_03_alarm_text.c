#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
  setlocale(0, "RUS");
  printf("\aНапуганная внезапным звуком, Вика вскрикнула:\n\"Во имя всех звезд, что это было!\"");
    return 0;
}
