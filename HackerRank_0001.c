#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//7 7 7 7 7 7 7 7 7 7 7 7 7
//7 6 6 6 6 6 6 6 6 6 6 6 7
//7 6 5 5 5 5 5 5 5 5 5 6 7
//7 6 5 4 4 4 4 4 4 4 5 6 7
//7 6 5 4 3 3 3 3 3 4 5 6 7
//7 6 5 4 3 2 2 2 3 4 5 6 7
//7 6 5 4 3 2 1 2 3 4 5 6 7
//7 6 5 4 3 2 2 2 3 4 5 6 7
//7 6 5 4 3 3 3 3 3 4 5 6 7
//7 6 5 4 4 4 4 4 4 4 5 6 7
//7 6 5 5 5 5 5 5 5 5 5 6 7
//7 6 6 6 6 6 6 6 6 6 6 6 7
//7 7 7 7 7 7 7 7 7 7 7 7 7

int main()
{

    int n;
    scanf("%d", &n);
    //fflush(stdin);
  	// Complete the code to print the pattern.

    for(int i = 0; i < n; ++i)
    {
      for(int j = 0; j <= i; ++j)
        printf("%d ", n - j);

      for(int j = 2*n - i - 2; j > i; --j)
        printf("%d ", n - i );

      for(int j = 2*n - i ; j < 2*n; ++j)
        printf("%d ", n + j - 2*n + 1  );
        printf("\n");
    }

    for(int i = n-2; i >= 0; --i)
    {
      for(int j = 0; j <= i; ++j)
        printf("%d ", n - j);

      for(int j = 2*n - i - 2; j > i; --j)
        printf("%d ", n - i );

      for(int j = 2*n - i ; j < 2*n; ++j)
        printf("%d ", n + j - 2*n + 1  );
        printf("\n");
    }
    return 0;
}
