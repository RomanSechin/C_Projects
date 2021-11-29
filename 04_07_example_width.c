#include <stdio.h>
#define PAGES 959

int main()
{
  const double RENT = 3852.99;

  printf("*%d*\n", PAGES);
  printf("*%2d*\n", PAGES);
  printf("*%10d*\n", PAGES);
  printf("*%-10d*\n\n", PAGES);

  printf("*%f*\n",RENT);
  printf("*%e*\n",RENT);
  printf("*%4.2f*\n",RENT);
  printf("*%3.1f*\n",RENT);
  printf("*%10.3f*\n",RENT);
  printf("*%10.3E*\n",RENT);
  printf("*%+4.2f*\n",RENT);
  printf("*%010.2f*\n",RENT);

  return 0;
}
/** \brief


*959*
*959*
*       959*
*959       *

*3852.990000*
*3.852990e+00
*3852.99*
*3853.0*
*  3852.990*
*3.853E+003*
*+3852.99*
*0003852.99*

 */
