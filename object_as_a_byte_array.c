#include <stdio.h>

int main()
{
    unsigned value = 0x1234;
    unsigned char * ptr = (unsigned char *)&value;
    int i;
    for(i = 0; i < sizeof value; ++i)
        printf("%02x", ptr[i]);
    putchar('\n');
    return 0;
}
