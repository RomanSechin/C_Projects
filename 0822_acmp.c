/*

*/
#include <stdio.h>
#include <stdlib.h>
long long  area(long long  x1,long long  y1,long long  x2,long long  y2,long long  x3,long long  y3)
{
    return ((x2-x1)*(y3-y1) - (y2-y1)*(x3-x1));
}

int main()
{
    FILE * in = fopen("INPUT.TXT", "r");
    FILE * out = fopen("OUTPUT.TXT", "w");

    long long  x1 = 0;
    long long  y1 = 0;
    long long  x2 = 0;
    long long  y2 = 0;
    long long  x3 = 0;
    long long  y3 = 0;
    long long  S = 0;

    fscanf(in,"%lld %lld %lld %lld %lld %lld", &x1, &y1, &x2, &y2, &x3, &y3);

    S = area(x1, y1, x2, y2, x3, y3);
    if(S < 0) S*= -1;

    if(S%2 == 0)
        fprintf(out, "%lld", S/2);

    else
        fprintf(out, "%.1f", (double)S/2.0);

    fclose(in);
    fclose(out);

    return 0;
}
