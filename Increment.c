#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
//7.7 i++
//7.7 ++i
//1.1 register
//1.1 -O3

int main()
{
    register unsigned long long sum = 0;
    for(register unsigned i = 0; i < UINT_MAX; ++i)
    {
        ++sum;
    }
    printf("%u\n", sum);
    return 0;
}
