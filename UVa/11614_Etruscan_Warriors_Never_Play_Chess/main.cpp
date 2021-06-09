#include <stdio.h>
#include <cmath>

using namespace std;

int main()
{
  int n;
  unsigned long long int v;
  scanf("%d", &n);
  while (n--) {
    scanf("%llu", &v);
    long long int delta = 1 + (4 * 2 * v);
    printf("%llu\n", (long long int)((sqrt(delta) - 1.0) / 2));
  }
  return 0;
}
