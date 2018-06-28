#include<cmath>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<numeric>
#include<iterator>

using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> vec;
  vec.resize(5);
  for(int i = 0; i < n; i++)
  {
    int temp;
    cin >> temp;
    vec[temp-1]++;
  }
  int max = *max_element(vec.begin(), vec.end());
  //copy(vec.begin(), vec.end(), ostream_iterator<double>(cout,"\t"));
  //cout << endl;
  for(int i = 0; i < vec.size(); i++)
  {
    if(vec[i] == max)
    {
      cout << i+1 << endl;
      break;
    }
  }
  return 0;
}
