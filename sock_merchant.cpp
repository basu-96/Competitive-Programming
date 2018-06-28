#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  int n;
  int pairs = 0;
  int itr = 0;
  cin  >> n;
  vector<int> colors(n);
  for (int i = 0; i < n; i++)
  {
    cin >> colors[i];
  }
  while(itr < n/2)
  {
    int temp = 0;
    vector<int>::iterator it;
    vector<int>::iterator it2;
    it = colors.begin();
    int check = colors[0];
    colors.erase(it);
    for(it2 = colors.begin(); it2 != colors.end(); it2++)
    {
      if (check == *it2)
      {
        temp++;
        colors.erase(it2);
      }
    }
    pairs = pairs + temp/2;
    cout << check << '\t' << temp/2 << endl;
    itr++;
  }

  cout << pairs << endl;

  return 0;
}
