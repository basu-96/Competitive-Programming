Problem statment : https://www.hackerrank.com/challenges/sherlock-and-array
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int t;
    cin >> t;
    while(t--){
        int size;
        int tailsum,headsum;
        int flag;
        headsum = tailsum = 0;
        cin >> size;
        int a[size];
        for(int i = 0; i < size; i++){
            cin >> a[i];
            tailsum = tailsum + a[i];
        }
        int totalsum = tailsum;
        for(int i = 1; i < size; i++){
           // tailsum = headsum = 0;
            headsum += a[i-1];
            tailsum = totalsum - (headsum + a[i]);
            flag = headsum^tailsum;
            if(!flag)
                break;
        }
        if(flag)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    } 
    return 0;
}
