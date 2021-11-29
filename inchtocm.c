#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s1[80];
    int inch = 0;

    printf("inches:\n");
    inch = (int)atoi(fgets(s1, 80, stdin));

    printf("cm\n%.4f",(float)inch*2.54);

    return 0;


}
