#include <stdio.h>
//#include <stdlib.h>
//#include<limits.h>

int main()
{
    int k = 0;
    float e1, e = 1.0;
M:  e /= 2.0;
    e1 = e + 1;
    ++k;
    if(e1>1.0) goto M;

    printf("\n����� ������� �� 2: %6d\n", k);
    printf("�������� ����: %e\n", e);
    //printf("FLT_EPSILON = %6d\nDBL_EPSILON = %6d\n", FLT_EPSILON, DBL_EPSILON);
    return 0;
}
