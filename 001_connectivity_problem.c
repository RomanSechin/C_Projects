#include <stdio.h>
#include <stdlib.h>
#define N 1000

int main()
{
    int i, j, p, q, id[N];

    for(i = 0; i < N; ++i)
        id[i] = i;


    while(2 == scanf( "%d %d\n", &p, &q))
    {
        for(i = p; i != id[i]; i = id[i]);
        for(j = q; j != id[j]; j = id[j]);

        if(i == j)
        {
            continue;
        }

        id[i] = j;

        printf("\t%d %d\n", p, q);
    }
    return 0;
}
