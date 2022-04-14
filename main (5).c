#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#ifndef M_PI
#define M_PI 3.141592
#endif // M_PI
double pr1(double a, double b, int n, double(*pf1)(double));
double f1(double x);
double f2(double t, double k);
double pr2(double a, double b, int n, double(*pf2)(double), double k);
double B_k(double k);
double f3(double t, double k);
double UT(int k, double t);
double pr3(double a, double b, int n, double(*pf3)(double), double k);
double fun(double t);
double A_k(double k);
double U_0();
void K();
double Umk(int n);
double U_m(int m, double t);
int i = 0;
double T = 1;
double A[4], B[4], UMK[4], U0, w = 2 * M_PI;
double f(double t);

int N;
double H;

void Print(FILE* f, double value)
{
    char buffer[80];
    sprintf(buffer, "%2.6lf\t", value);
    fprintf(f, "%s", buffer);
}

void main()
{
    N = 1000;
    H = (T/2 - -T/2) / N;

    setlocale(LC_ALL, "Russian");

    FILE* f = stdout;//fopen("result_u.csv", "w");

    int n = 50;
    double h = (T/2 - -T/2) / n;
    double a = -1.5, b = 1.5;

    fprintf(f, "t\t\tfun(t)\t\tU4(t)\t\tU20(t)\t\tU50(t)\t\n");


    for (double t = a * T; t < b * T + h; t += h)
    {
        Print(f, t);
        Print(f, fun(t));
        Print(f, U_m(4, t));
        Print(f, U_m(20, t));
        Print(f, U_m(50, t));
        fprintf(f, "\n");
    }

    //fclose(f);

    //f = fopen("result_Umk.csv", "w");
    fprintf(f, "\nU0\t\tUmk\n");

    for (int k = 1; k <= 50; k++)
    {
//        Print(f, U_0());
//        Print(f, Umk(k));
//        fprintf(f, "\n");
//
        Print(stdout, U_0());
        Print(stdout, Umk(k));
        fprintf(stdout, "\n");
    }

    //fclose(f);

}

// ---------------------------------------------------------
double fun(double t)
{
    t = (t / T - (int)t / T) * T;
    if (t < -T / 2)
        t += 1;
    if (t >= T / 2)
        t -= 1;
    if (t >= 0)
        return (2.0 - exp(-t / T));
    else
        return (-0.5 + exp(-t / T));
}
double U_0()
{
    double a = -0.5, b = 0.5;
    double s1, s2 = 1e10, eps = 1e-6;
    int n = 100;
    do
    {
        s1 = s2;
        n *= 2;
        s2 = pr1(a, b, n, f1);

    } while (fabs(s1 - s2) > eps);
    return s2;
}
double f1(double t)
{
    return 2 / T * (fun(t));
}
double pr1(double a, double b, int n, double(*pf1)(double))
{
    double h = (b - a) / n, x, S = 0;
    for (x = a + h / 2; x < b; x += h)
        S += f1(x);
    return S * h;
}
double A_k(double k)
{
    double a = -0.5, b = 0.5;
    double s1, s2 = 1e10, eps = 1e-6;
    int n = 100;
    do
    {
        s1 = s2;
        n *= 2;
        s2 = pr2(a, b, n, f2, k);

    } while (fabs(s1 - s2) > eps);
    return s2;
}
double f2(double t, double k)
{
    return (2 / T) * (fun(t)) * cos((w * k / T * t));
}
double pr2(double a, double b, int n, double(*pf2)(double), double k)
{
    double h = (b - a) / n, x, S = 0;
    for (x = a + h / 2; x < b; x += h)
        S += f2(x, k);
    return S * h;
}
double B_k(double k)
{
    double a = -0.5, b = 0.5;
    double s1, s2 = 1e10, eps = 1e-6;
    int n = 100;
    do
    {
        s1 = s2;
        n *= 2;
        s2 = pr3(a, b, n, f3, k);
    } while (fabs(s1 - s2) > eps);
    return s2;
}
double f3(double t, double k)
{
    return (2 / T) * (fun(t)) * sin(w * k * t);
}
double pr3(double a, double b, int n, double(*pf3)(double), double k)
{
    double h = (b - a) / n, x, S = 0;
    for (x = a + h / 2; x < b; x += h)
        S += f3(x, k);
    return S * h;
}


double UT(int k, double t)
{
    double l = 0;
    int m = 1;
    for (m = 1; m <= k; m++)
        l += (A[m - 1] * cos((w * m * t)) + B[m - 1] * sin((w * m * t)));
    return l + U0 / 2;
}
void K()
{
    int m = 4;
    int n;
    for (n = 0; n <= m; n++)
    {
        A[n] = A_k(n + 1);
        B[n] = B_k(n + 1);
        UMK[n] = Umk(n);
    }
    U0 = U_0();
}

double U_m(int c, double t)
{
    double sum = U_0() / 2;
    for (int k = 1; k <= c; k++)
    {
        sum += A_k(k) * cos(w * k * t) + B_k(k) * sin(w * k * t);
    }
    return sum;
}

double Umk(int n)
{
    return sqrt(A[n] * A[n] + B[n] * B[n]);
}
