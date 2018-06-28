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
vector <int> quickSort(vector <int>  ar, int ar_size) {
    vector<int> left, right;
    int pivot;

    if (ar_size <= 1)
        return ar;

    pivot = ar[0];
    for (int i = 1; i < ar_size; i++){
        if (ar[i] <= pivot) {
            left.push_back(ar[i]);
        } else {
            right.push_back(ar[i]);
        }
    }

    left = quickSort(left, left.size());
    right = quickSort(right, right.size());
    left.push_back(pivot);
    for (int i = 0; i < right.size(); i++)
        left.push_back(right[i]);


    for (int i = 0; i < left.size(); i++)
        cout << left[i] << ' ';
    cout << endl;

    return left;
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

    _ar = quickSort(_ar, _ar_size);

    return 0;
}
