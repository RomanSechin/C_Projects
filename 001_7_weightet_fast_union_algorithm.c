//Приведите содержимое массива id после выполнения каждой операции union при использовании
//алгоритма взвешенного быстрого объединения для решения задачи связности для последовательности
//0-2, 1-4, 2-5, 3-6, 0-4, 1-3
//Укажите также количество обращений программы к массиву id для каждой вводимой пары
#include <stdio.h>
#define N 1000

int main()
{
    int i, j, p, q, id[N], sz[N], count_of_query_to_id;

    for(int i = 0; i < N; ++i)
    {
        id[i] = i;
        sz[i] = 1;
    }

    while(scanf("%d %d", &p, &q) == 2)
    {
        count_of_query_to_id = 0;
        for(i = p; i != id[i]; i = id[i])
        {
            id[i] = id[id[i]];
            count_of_query_to_id += 5;
        }
        for(j = q; j != id[j]; j = id[j])
        {
            count_of_query_to_id += 5;
            id[j] = id[id[j]];
        }

        if(i == j) continue;

        if(sz[i] < sz[j])
        {
            id[i] = j;
            sz[j] += sz[i];
        }
        else
        {
            id[j] = i;
            sz[i] += sz[j];
        }
        printf("\t%d %d count_of_query_to_id = %d\n", p, q, count_of_query_to_id);
    }


    return 0;
}
