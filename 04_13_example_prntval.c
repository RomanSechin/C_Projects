#include <stdio.h>
#include <locale.h>

int main()
{
  setlocale(    0, "RUS");
  int bph2o = 212;
  int rv;

  rv = printf("���� �������� ��� %d �������� �� ����������.\n", bph2o);
  printf("������� printf() ������ %d ��������.\n", rv);

  return 0;
}
