#include<bits/stdc++.h>


using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    stack <int> nest;
    vector <int> subSymb;
    int nestDepth = 0, maxSymb = 0,maxsymbIndex,minnestIndex=0;
    subSymb.push_back(0);
    for(int i =0; i < n; i++){
        if (arr[i] == 1) nest.push(1);
        if (arr[i] == 2) nest.pop();
        int stack_size = nest.size();
        if (nestDepth < stack_size){
            minnestIndex = i+1;
            nestDepth = stack_size;
        }
        if (stack_size == 0){
            subSymb.push_back(i+1);
        }
    }
    int arr_size = subSymb.size();
    for(int i = 0; i < arr_size-1; i++){
        if (maxSymb < subSymb[i+1]-subSymb[i]){
            //cout << "AAAA" << endl;
            //maxsymbIndex = subSymb[i]+1;
            maxSymb =  subSymb[i+1]-subSymb[i];
            maxsymbIndex = subSymb[i] + 1;
        }
    }
    cout << nestDepth << " " << minnestIndex  << " " << maxSymb << " " << maxsymbIndex  << endl;
    return 0;
}
