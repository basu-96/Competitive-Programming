//Problem link - https://www.codechef.com/JULY20B/problems/PTMSSNG

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
    int n,i,x,y;
    cin >> n;
    map<int, int> mpx,mpy;
    rep(i,4*n-1){
        cin >> x >> y;
        mpx[x]++;
        mpy[y]++;
    }
    map<int, int>::iterator it;
    for(it=mpx.begin(); it!=mpx.end(); it++){
        if(it->second % 2 != 0) x = it->first;
    }
    for(it=mpy.begin(); it!=mpy.end(); it++){
        if(it->second % 2 != 0) y = it->first;
    }
    cout << x << " " << y << endl;
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
