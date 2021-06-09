#include <stdio.h>
#include <string>

using namespace std;

int main()
{
  int n, a;
  scanf("%d", &n);
  while (n--)
  {
    scanf("%d", &a);
    int a2 = (((a * 63) + 7492) * 5) - 498;
    string s = to_string(a2);
    char ch = s[s.length() - 2];
    printf("%d\n", (int)ch - 48);
  }
  return 0;
}