/*

*/
#include <stdio.h>
#include <stdlib.h>

int NOD(int a, int b)
{

    if (b == 0)
        return a;
    else
        return NOD(b, a % b);
}
int main()
{
    FILE * in = fopen("INPUT.TXT", "r");
    FILE * out = fopen("OUTPUT.TXT", "w");

    int N = 0;
    int M = 0;

    fscanf(in, "%d %d", &N, &M);
    fprintf(out, "%d", NOD(N, M));

    fclose(in);
    fclose(out);

    return 0;
}
