#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
  setlocale(0,"RUS");
  float cups;
    printf("������� ���������� �����: ");
    scanf("%f", &cups);
    printf("��� %f ����, %f �����, %f �������� ����� � %f ������ �����.", cups*2, cups/8, cups/16, cups/48);
    return 0;
}
