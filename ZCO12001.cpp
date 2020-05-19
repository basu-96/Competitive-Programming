#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    // Nesting depth variables
    int flag = 0,nestDepth = 0,maxDepth = 0;
    int nestIndex, minIndex = INT_MAX;
    // Max num of symbols variables
    for(int i = 0; i < n; i++){
        if(arr[i] == 1){
            flag++;
        }    
        else{
            nestDepth++;
            flag--;
        }
        if (flag == 0){
            cout << nestDepth << endl;
            if (maxDepth < nestDepth){
                maxDepth = nestDepth;
                 nestIndex = i + 1 - nestDepth;
                 if (nestIndex < minIndex){
                    minIndex = nestIndex;
                 }
            }
            nestDepth = 0;
        }
    }
   // cout << maxDepth << endl;
   // cout << minIndex << endl;
    return 0;
}
