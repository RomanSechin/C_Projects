#include <stdio.h>
#include <inttypes.h>

int main()
{
  unsigned int un = 3000000000;
  short end = 200;
  long big = 65537;
  long long verybig = 12345678908642;

  int32_t me32 = 459339450;

  printf("un = %u, but not %d\n", un, un);
  printf("end = %hd and %d\n", end, end);
  printf("big = %ld, but not %hd\n", big, big);
  printf("verybig = %lld, but not %ld\n", verybig, verybig);

  printf("me32 = %d\n", me32);
  printf("me32 = %" PRId32 "\n", me32);

  return 0;
}
