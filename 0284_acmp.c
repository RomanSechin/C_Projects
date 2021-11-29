/*

*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE * in = fopen("INPUT.TXT", "r");
    FILE * out = fopen("OUTPUT.TXT", "w");

    int N = 0;
    fscanf(in, "%d", &N);
    long long array[N];// = (long long *)malloc(N*sizeof(long long));
    for(int i = 0; i < N; ++i)
    {
        fscanf(in, "%lld", &array[i]);
    }
    fscanf(in, "%d", &N);
    int subarray[2];
    for(int i = 0; i < N; ++i)
    {
        fscanf(in, "%d %d", &subarray[0], &subarray[1]);
        for(int j = subarray[0]; j <= subarray[1]; ++j)
        {
            fprintf(out, "%d ", array[j-1]);
        }
        fprintf(out, "\n");
    }


    fclose(in);
    fclose(out);

    return 0;
}
