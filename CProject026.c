#include <stdio.h>


int main()
{
    int card = 1;
    if(card > 1)
    {
    card = card-1;

    if(card < 7)
        puts("cheap card");
    else
        puts("Tuz!");
    }
    return 0;
}
