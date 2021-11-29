//Напишите программу, аналогичную 001_4, используя алгоритм quick union
////Приведите содержимое массива id после выполнения каждой операции union при использовании
//алгоритма быстрого поиска (программа 1.1) для решения задачи связности для последовательности
//0-2, 1-4, 2-5, 3-6, 0-4, 1-3
//Укажите также количество обращений программы к массиву id для каждой вводимой пары
#include <stdio.h>
#define N 1000

int main()
{
    int i, j, p, q, id[N];
    int count_of_query_to_id = 0;

    for(i = 0; i < N; ++i)
        id[i] = i;
    while(scanf("%d %d", &p, &q) == 2)
    {
        for(i = p; i != id[i]; i = id[i]) ++count_of_query_to_id;
        for(j = q; j != id[j]; j = id[j]) ++count_of_query_to_id;

        if(i == j) continue;

        id[i] = j;
        ++count_of_query_to_id;

        printf("\t%d %d count_of_query_to_id = %d\n", p, q, count_of_query_to_id);
    }

    return 0;
}
