#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
  setlocale(0,"RUS");

  float v, file_size;
  printf("������� �������� �������� � ��������� � ������� � ������ ����� � ����������:\n");
  scanf("%f %f", &v, &file_size);
  printf("��� �������� �������� %.2f ������� � ������� ���� �������� %.2f �������� ����������� %.2f ������(�).\n",v, file_size, 8*file_size/v);
  return 0;
}
