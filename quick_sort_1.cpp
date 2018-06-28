#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
void partition(vector <int>  ar) {
    vector <int> l; vector <int> ge;
    for(int i=0;i<ar.size();i++){
        if(ar[i]>=ar[0]){
            ge.push_back(ar[i]);
        }
        else{
            l.push_back(ar[i]);
        }
    }

    for(int i=0;i<l.size();i++)
        cout<<l[i]<<" ";
    for(int i=0;i<ge.size();i++)
        cout<<ge[i]<<" ";
}
int main(void) {
   vector <int>  _ar;
   int _ar_size;
cin >> _ar_size;
for(int _ar_i=0; _ar_i<_ar_size; _ar_i++) {
   int _ar_tmp;
   cin >> _ar_tmp;
   _ar.push_back(_ar_tmp);
}

partition(_ar);

   return 0;
}

