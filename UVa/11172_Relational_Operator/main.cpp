#include <stdio.h>

using namespace std;

int main()
{
  int n, a, b;
  scanf("%d", &n);
  while (n--)
  {
    scanf("%d %d", &a, &b);
    if (a > b) {
      printf("%s\n", ">");
    }
    else if (a < b) {
      printf("%s\n", "<");
    }
    else {
      printf("%s\n", "=");
    }
  }
  return 0;
}