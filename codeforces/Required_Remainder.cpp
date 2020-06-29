//
// Problem statement - https://codeforces.com/contest/1374/problems
//

#include<bits/stdc++.h>
using namespace std;

#define f(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) f(i,0,n)
#define fd(i,a,b) for(i=a;i>=b;i--)
#define lli long long int
#define vi vector<int>
#define vll vector<lli>
#define pb push_back
#define all(v) v.begin(),v.end()

void solve(){
    int x, y, n;
    cin >> x >> y >> n;
    if ((n/x)*x+y <= n){
        cout << (n/x)*x+y << "\n";
    }else{
        cout << (n/x-1)*x+y << "\n";
    }
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

