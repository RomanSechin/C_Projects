#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
  setlocale(0,"RUS");
  int n;
  unsigned long long sum = 0;
  printf("������� �����: ");
  scanf("%d", &n);
  while(n > 0)
  {
    int i = 0;
    while(i <= n)
    {
      sum += i;
      ++i;
    };
    printf("%d\n", sum);
    sum = 0;
    printf("������� ����� (<= ��������� ������): ");
    scanf("%d",&n);
  }
  printf("������ ��������.");
  return 0;
}
