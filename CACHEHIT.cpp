#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n,b,m;
    cin >> n >> b >> m;
    int ans = 0;
    int num;
    cin >> num;
    int curr_block = num/b;
    ans++;
    for(int i = 0; i < m-1; i++){
        cin >> num;
        while(curr_block != num/b){
            ans++;
            curr_block = num/b;
        }
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int test_cases;
    //test_cases = 1;
    cin >> test_cases;
    while(test_cases--){
        solve();
    }
    return 0;
}

