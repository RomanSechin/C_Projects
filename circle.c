//Программа находит площадь пересечения двух кругов
//В программе есть несколько потенциальных проблем
//Каких?

#include <stdio.h>

int main()
{
    unsigned long long area = 0;
    long x = 0, y = 0;
    long r1 = 2000;
    long r2 = 2000;
    long x01 = 2000;
    long y01 = 2000;
    long x02 = 4000;
    long y02 = 2000;
    long x_left = 0;
    long x_right = 6000;
    long y_low = 0;
    long y_top = 4000;
    long long R1 = r1*r1;
    long long R2 = r2*r2;

    for(x = x_left; x < x_right; ++x)
       for(y = y_low; y < y_top; ++y)
        if((long long)((x - x01)*(x - x01) + (y - y01)*(y - y01)) < R1 &&
           (long long)((x - x02)*(x - x02) + (y - y02)*(y - y02)) < R2)
        ++area;

    printf("Area is %ld\n", area);

    return 0;
}
