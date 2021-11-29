//��������� ���������� ������ 8-�� ������� ����� �� ����� � ������,
//����� �������� ���������� ����� "original.txt" �� ���� �����
//����� ����������� ���� �� ���� �� �����
//�� ������ ����� ��������� ���������� �� ������ ���������� �����
//27.11.2021

#include <stdio.h>
#include <stdlib.h>
#include "binary.h"
#include <math.h>

char * char2bin(unsigned char n);
int bin2int(char str[8]);
int inputMask();
int create_binary_h();
char * char2bin(unsigned char n);
void print_file(char * fname, char * message);

int main()
{
    system("chcp 1251 > 0");

    print_file("original.txt", "����������� ���������� �����");

    int mask = inputMask();

    FILE * f_original;
    f_original = fopen("original.txt", "rb+");

    char chr;// ��� �������� ������� �� �����
    char chr_secret;// ��� �������� ������������� �������

    // ������ ������ �� �����, �������� ���, ������������ � ������������ ������� � �������� ���
    // ��������������
    while(fread(&chr, sizeof(chr), 1, f_original))
    {
        chr_secret = chr ^ mask;
        chr_secret = ~chr_secret;
        fseek(f_original, -1 * sizeof(chr_secret), SEEK_CUR);
        fwrite(&chr_secret, sizeof(chr_secret), 1, f_original);
        fseek(f_original, 0 * sizeof(chr_secret), SEEK_CUR);
    }
    printf("\n");
    fclose(f_original);//��������� ����
    //������ ���������� ����� ����� �����������
    print_file("original.txt", "���������� ����� ����� �����������");

    // ��������� ���� ����� ��� ��������������
    f_original = fopen("original.txt","rb+");
    while(fread(&chr, sizeof(chr), 1, f_original))
    {
        chr_secret = ~chr;
        chr_secret = chr_secret ^ mask;
        fseek(f_original, -1 * sizeof(chr_secret), SEEK_CUR);
        fwrite(&chr_secret, sizeof(chr_secret), 1, f_original);
         fseek(f_original, 0 * sizeof(chr_secret), SEEK_CUR);
    }
    fclose(f_original);
    //������������� ���������� ����� ����� ��������������
    print_file("original.txt", "���������� ����� ����� ��������������");
    return 0;
}
//������� �������������� ������ � ��������� � ������ � �����
int bin2int(char str[8])
{
    int n = 0;
    for(int i = 0; i < 8; ++i)
    {
        if(str[i] == 1)
            n+= pow(2, 7-i);
    }
    return n;
}
// ���������� ��� �������� ����� �������� �����
int inputMask()
{
    char mask[9];
    printf("������� ����� ��� �����������:");
    fflush(stdin);
    while(fscanf(stdin, "%8s", mask) != 1)
    {
        for(int i = 0; i < 9; ++i)
        {
            if(mask[i] != '1' && mask[i] != '0' && mask[i] != '\n' && mask[i] != '\0')
                printf("������������ ����. ����������� 8 �������� '0' �/��� '1'!\n");
            break;
        }
        printf("������� ����� ��� �����������:");
        fflush(stdin);
    }
    mask[8] = '\0';
    return bin2int(mask);
}

//������� �������������� ����� � �������� ������
char * char2bin(unsigned char n)
{
    static char str[9];
    unsigned char b = b10000000;
    unsigned char result = 0;

    for(unsigned i = 0; i < 8; ++i)
    {
        result = n & b;
        if(result > 0)
            str[i] = '1';
        else
            str[i] = '0';
        n <<= 1;
    }
    str[8] = '\0';
    return str;
}
// ������� ������ ����������� ����� fname � ������������ ���������� message
void print_file(char * fname, char * message)
{
    printf("%s:\n", message);
    FILE * filename;
    filename = fopen(fname, "rb+");
    if(filename == NULL)
    {
        printf("can't open file");
        exit(5);
    }
    char chr;
    while(fread(&chr, sizeof(chr), 1, filename))
    {
        printf("%c", chr);
    }
    printf("\n");
}
