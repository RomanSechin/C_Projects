#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
	setlocale(0,"RUS");

	int age;
	float assets;
	char pet[30];

	printf("������� ���������� � ���� ��������, ����� � ����� � ������� ��������.\n");
	scanf("%d %f", &age, &assets);
	scanf("%s", pet);
	printf("%d $%.2f %s\n", age, assets, pet);
  return 0;
}
