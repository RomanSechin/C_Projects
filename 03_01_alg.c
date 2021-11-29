#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double avg2(int r, int N)
{
    int num;
    double m1 = 0;
    for(int i = 0; i < N; ++i)
    {
        num = rand() % N;
        m1 += (double)num/N;
    }
    return m1;
}

double sigma2(int r, int N)
{
    int num;
    double m2 = 0;
    for(int i = 0; i < N; ++i)
    {
        num = rand() % r;
        m2 += ((double)num / N ) * num;
    }

    double m1 = avg2(r, N);
    return sqrt(m2 - m1*m1);
}

int main()
{
    double num, m1, m2;
    for(int r = 10; r <= 1000; r *= 10)
        for(int N = 1E3; N <= 1E6; N *= 10)
        {
            for(int i = 0; i < N; ++i)
            {
                num = (double)(rand() % r);
                m1 += num / N;
                m2 += (num / N) * num;
            }

            printf("r = %d, N = %d, average^2  == %.3f\n", r, N, m1);
            printf("r = %d, N = %d, sigma^2  == %.3f\n", r, N, sqrt(m2 - m1*m1));
            m1 = 0;
            m2 = 0;
            num = 0.0;
        }

    return 0;
}
