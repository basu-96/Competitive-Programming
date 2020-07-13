// Problem link - https://www.codechef.com/JULY20B/problems/CRDGAME

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

lli sumdigits(lli n){
    lli sum = 0;
    while(n){
        sum+=n%10;
        n/=10;
    }
    return sum;
}

void solve(){
    lli n,i,chef_rounds=0,morty_rounds=0;
    cin >> n;
    rep(i,n){
       lli t1, t2;
       cin >> t1 >> t2;
       if(sumdigits(t1) < sumdigits(t2)){
          morty_rounds++;
       }else if(sumdigits(t2) < sumdigits(t1)){
          chef_rounds++;
       }else{
          morty_rounds++;
          chef_rounds++;
       }
    }
    if(morty_rounds < chef_rounds){
        cout << 0 << " " << chef_rounds << endl;
    }else if(chef_rounds < morty_rounds){
        cout << 1 << " " << morty_rounds << endl;
    }else{
        cout << 2 << " " << chef_rounds << endl;
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
