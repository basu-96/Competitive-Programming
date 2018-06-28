#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> vec;
        for(int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            vec.push_back(temp);
        }
        sort(vec.begin(), vec.end());
        int time = 0;
        for(int i = 0; i < vec.size()-1; i++)
        {
            time = time + vec[i+1] - vec[i];
        }
        cout << time;
    }

    return 0;
}
