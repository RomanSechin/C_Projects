#include <math.h>
#include <stdio.h>
#include<graphics.h>
int main()
{
    float xA, yA, xB, yB, xC, yC, xD, yD,
    xxA, yyA, xxB, yyB, xxC, yyC, xxD, yyD, p, q;
    int i;
    p=0.95;q=1.0-p;
    xA=2.0; xB=8.0; xC=8.0; xD=2.0;
    yA=0.5; yB=0.5; yC=6.5; yD=6.5;
    initgr();
    for (i = 0; i < 50; i++)
    {
        move(xA, óA);
        draw(xB, yB); draw(xC, yC); draw(xD, yD); draw(xA, yA);
        xxA=p*xA+q*xB; yyA=p*yA+q*yB; xxB=p*xB+q*xC; yyB=p*yB+q*yC;
        xxC=p*xC+q*xD; yyC=p*yC+q*yD; xxD=p*xD+q*xA; yyD=p*yD+q*yA;
        xA=xxA; xB=xxB; xC=xxC; xD=xxD;
        yA=yyA; yB=yyB; yC=yyC; yD=yyD;
    }
        endgr();

    return 0;
    /* */
}
