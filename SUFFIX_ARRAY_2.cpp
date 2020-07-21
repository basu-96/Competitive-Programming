#include<bits/stdc++.h>
using namespace std;

#define f(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) f(i,0,n)
#define fd(i,a,b) for(i=a;i>=b;i--)
#define ll long long int
#define vi vector<int>
#define vll vector<lli>
#define pb push_back
#define all(v) v.begin(),v.end()
#define endl "\n"

ll gcd(ll a, ll b){
    if(a == 0){
        return b;
    }
    if(b==0){
        return a;
    }
    if(a == b){
        return a;
    }
    if(a > b){
        return gcd(a-b,b);
    }else{
        return gcd(a,b-a);
    }
}

bool isprime(ll n){
    if(n == 1) return false;
    ll i;
    for(i = 2; i*i<=n; i++){
        if(n%i==0) return false;
    }
    return true;
}

void radix_sort(vector<pair<pair<int,int>, int>> &b){
    int n = b.size();
    {
    vector<int> cnt(n);
    for(auto x:b){
        cnt[x.first.second]++;
    }
    vector<pair<pair<int,int>, int>> b_new(n);
    vector<int> pos(n);
    pos[0] = 0;
    int i;
    f(i,1,n){
        pos[i] = pos[i-1] + cnt[i-1];
    }
    for(auto x:b){
        i = x.first.second;
        b_new[pos[i]] = x;
        pos[i]++;
    }
    b = b_new;
    }
    {
  
    vector<int> cnt(n);
    for(auto x:b){
        cnt[x.first.first]++;
    }
    vector<pair<pair<int,int>, int>> b_new(n);
    vector<int> pos(n);
    pos[0] = 0;
    int i;
    f(i,1,n){
        pos[i] = pos[i-1] + cnt[i-1];
    }
    for(auto x:b){
        i = x.first.first;
        b_new[pos[i]] = x;
        pos[i]++;
    }
    b = b_new;
    }
}

void solve(){
    string str;
    cin >> str;
    str += "$";
    int i;
    int n = str.size();
    vector<int> p(n), c(n);
    int k = 0;
    // k =0;
    vector<pair<char,int>> a(n);
    rep(i,n){
        a[i] = {str[i],i};
    }
    sort(all(a));
    rep(i,n){
        p[i] = a[i].second;
    }
    c[p[0]] = 0;
    f(i,1,n){
        if(a[i].first == a[i-1].first){
            c[p[i]] = c[p[i-1]];
        }else{
            c[p[i]] = c[p[i-1]] + 1;
        }
    }
    while((1<<k) < n){
        // k -> k + 1
        vector<pair<pair<int,int>, int>> b(n);
        rep(i,n){
            b[i] = {{c[i],c[(i+(1<<k))%n]},i};
        }
        radix_sort(b);
        rep(i,n){
            p[i] = b[i].second;
        }
        c[p[0]] = 0;
        f(i,1,n){
            if(b[i].first == b[i-1].first){
                c[p[i]] = c[p[i-1]];
            }else{
                c[p[i]] = c[p[i-1]]+1;
            }
        }
        k++;
    }
    rep(i,n){
        cout << p[i] << " ";
    }
    cout << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int test_cases;
    test_cases = 1;
    //cin >> test_cases;
    while(test_cases--){
        solve();
    }
    return 0;
}
