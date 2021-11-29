// ������ ������� �������� fwrite(). ��� ��������.
#include <stdio.h>
#define NUM 3

int main()
{
    unsigned short data1[NUM] = {12342, 12343, 12344};
    unsigned short data2[NUM] = {12345, 12345, 12345};

    FILE * fptr;
    fptr = fopen("array.dat","wb");
    for(int i = 0; i < NUM; i++)
        fwrite(&data1[i], sizeof(data1[i]), 1, fptr);
    fclose(fptr); // ��: ������� ��� ������ � ����������, ��� ������

    fptr = fopen("array.dat","ab");
    //fwrite(data2, sizeof(data2[0]), NUM, fptr);
    fwrite(data2, sizeof(data2), 1, fptr);
    fclose(fptr);
    // �� ���������� ��������� ����� �� ������ ����� ���������
    // � �������� "�����" ��� ���� ������
    return 0;
}

