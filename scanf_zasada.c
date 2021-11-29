// Читаем произвольно выбранный элемент базы данных
#include <stdio.h>

struct books
{
    char title[20];
    double price;
} temp, fantasy[3]={ {"The Witcher",   5.5 },
                     {"Black Company", 7.5 },
                     {"Wheel of time", 8.3 } };
int main()
{
    unsigned num = 0; // номер записи
    FILE * fbooks = fopen("books.dat", "wb+");
    fwrite(fantasy, sizeof(fantasy), 1, fbooks);

    while(1)// Была Ззсада!!!
    {
        puts("Enter number of books you want to see:");
        while(1 != scanf("%u", &num) || num < 0 || num >= 3)
        {
            fflush(stdin);
            puts("Enter number of books you want to see [0..2]:");
        }

        fflush(stdin);
        fseek(fbooks, sizeof(struct books)*(num-1), SEEK_SET);
        fread(&temp, sizeof(struct books), 1, fbooks);
        printf("%s - %.2f$\n", temp.title, temp.price);
    }

    fclose(fbooks);
    return 0;
}
