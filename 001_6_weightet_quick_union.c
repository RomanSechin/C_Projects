//ѕриведите содержимое массива шв после выполнени€ каждой операции union
//дл€ случаев использовани€ алгоритма взвешенного быстрого объединени применительно к примерам,
//соответствующим рис 1.7 и 1.8

#include <stdio.h>
#define N 10

int main()
{
    int i, j, p, q, id[N], sz[N], count_of_query_to_id = 0;
    for(i = 0; i < N; ++i)
    {
        id[i] = i;
        sz[i] = 1;
    }

    while(scanf("%d %d", &p, &q) == 2)
    {
        for(i = p; i != id[i]; i = id[i]) ++count_of_query_to_id;
        for(j = q; j != id[j]; j = id[j]) ++count_of_query_to_id;

        if(i == j) continue;

        if(sz[i] < sz[j])
        {
            id[i] = j;
            sz[j] += sz[i];
            ++count_of_query_to_id;
        }
        else
        {
            id[j] = i;
            sz[i] += sz[j];
            ++count_of_query_to_id;
        }

        for(i = 0; i < N; ++i)
        {
            printf("%d ", id[i]);
        }
        puts("");
        for(i = 0; i < N; ++i)
        {
            printf("%d ", sz[i]);
        }

        puts("");
        printf("\t%d %d count_of_query_to_id = %d\n", p, q, count_of_query_to_id);
    }

    return 0;
}
