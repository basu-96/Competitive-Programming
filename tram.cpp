#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int x, int y)
{
  while( y != 0)
  {
    int r = x % y;
    x = y;
    y = r;
  }
  return x;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    cout << gcd(6, 5) << endl;

    return 0;
}
