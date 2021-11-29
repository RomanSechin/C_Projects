// Запись массива функцией fwrite(). Два варианта.
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
    fclose(fptr); // ДЗ: удалить эту строку и посмотреть, что выйдет

    fptr = fopen("array.dat","ab");
    //fwrite(data2, sizeof(data2[0]), NUM, fptr);
    fwrite(data2, sizeof(data2), 1, fptr);
    fclose(fptr);
    // ДЗ переписать программу чтобы во второй части программы
    // в качестве "блока" был весь массив
    return 0;
}

