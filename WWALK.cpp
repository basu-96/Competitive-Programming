#include<bits/stdc++.h>
using namespace std;

bool checkArray(int arr[], int n){
    bool ans = true;
    for(int i = 0; i < n; i++){
        if (arr[i]==1){
            ans = false;
            break;
        }
    }
    return ans;
}

int main(){
    int test_cases;
    cin >> test_cases;
    while(test_cases--){
        int n;
        cin >> n;
        long long ans = 0, distA = 0, distB = 0;
        int a[n],b[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        for(int i = 0; i < n; i++){
            cin >> b[i];
            if (b[i]==a[i] && distA == distB){
                ans += b[i];
            }
            distA += a[i];
            distB += b[i];
        }
        cout << ans << endl;
    }

    return 0;
}
