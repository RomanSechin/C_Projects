/*

*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE * in = fopen("INPUT.TXT", "r");
    FILE * out = fopen("OUTPUT.TXT", "w");

    int count = 0;
    int age = 0;
    int sex = 0;
    int number = 0;
    int max_age = 0;

    fscanf(in, "%d", &count);

    for(int i = 0; i < count; ++i)
    {
        fscanf(in, "%d %d", &age, &sex);
        if(age > max_age && sex == 1)
        {
            max_age = age;
            number = i+1;
        }
    }
    if(number == 0) number = -1;
    fprintf(out, "%d", number);

    fclose(in);
    fclose(out);

    return 0;
}
