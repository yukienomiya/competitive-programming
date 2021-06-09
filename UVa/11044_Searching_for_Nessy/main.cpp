#include <stdio.h>

using namespace std;

int main() {
  int n, a, b;
  scanf("%d", &n);
  while (n--) {
    scanf("%d %d", &a, &b);
    int a2 = (int)(a / 3);
    int b2 = (int)(b / 3);
    printf("%d\n", a2 * b2);
  }
  return 0;
}