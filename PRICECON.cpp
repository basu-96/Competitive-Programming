#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int test_cases;
    cin >> test_cases;
    while(test_cases--){
        int n,k,ans=0;
        cin >> n >> k;
        for(int i = 0; i < n; i++){
            int t;
            cin >> t;
            if (k < t) ans += t- k;
        }
        cout << ans << endl;
    }
    
    return 0;
}
