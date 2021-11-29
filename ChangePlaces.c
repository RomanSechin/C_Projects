/*����� ����� ������ ���� ������ ����� ����� �� 10 ���������.
������ �������� ������� ������ � ������ ������� � 9 � 10, 3 � 4 � 7 � 8.
�.� �������� ���� ��������
1 2 3 4 5 6 7 8 9 10 � �����
9 10 7 8 5 6 3 4 1 2

��������� ������ ������� �������� ��������������� ��������� ������� ������� size � ������������ � ����������� ������.
� ����� � ������ ������� �� �������� ������� half_size(= size / 2 ) ���������� ����  �������� ��������� �������:
������� � �������� index ������������ ��������� � ��������� � �������� size - index - 2,
� ������� � �������� index + 1 ������������ � ��������� � �������� size - index - 1
*/
//srv 03/05/2021
//ver 3.0

#include <stdio.h>

void print_array(int array[], int size)
{
    for(int index = 0; index < size; ++index)
        printf("%d ", array[index]);
    printf("\n\n");
}
int main()
{
    int size = 300;//������ �������
    if(size <= 3 )
    {
        printf("There are nothing to swap!\n");
        return 0;
    }
    int half_size = size / 2;//����� �������� ������� �������
    int temp = 0; //��������� ���������� ��� ���������� swap
    int * array = malloc(size * sizeof(int));//������ �������
    for(int index = 0; index < size; ++index)
    {
        array[index] = index;
    }
    print_array(array, size);//������ ������� � �������
    for(int index = 0; index < half_size; index += 2)
    {
        temp = array[index];
        array[index] = array[size - index - 2];
        array[size - index - 2] = temp;

        temp = array[index + 1];
        array[index + 1] = array[size - index - 1];
        array[size - index - 1] = temp;
    }
    print_array(array, size);
    free(array);
    return 0;
}
