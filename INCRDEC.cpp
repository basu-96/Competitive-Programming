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
  int n,i;
  cin >> n;
  vi arr(n),left,right;
  int freq[200005] = {0};
  rep(i,n){
      cin >> arr[i];
      freq[arr[i]]++;
  }
  sort(all(arr));
  if(freq[arr[n-1]] > 1){
      cout << "NO" << endl;
      return;
  }
  rep(i,n-1){
      if(freq[arr[i]] > 2){
          cout << "NO" << endl;
          return;
      }
  }
  cout << "YES\n";
  left.pb(arr[0]);
  f(i,1,n){
      if(left[(int)left.size()-1] < arr[i]){
          left.pb(arr[i]);
      }else{
          right.pb(arr[i]);
      }
  }
  //cout << left.size() << " " << right.size() << endl; 
  f(i,0,(int)left.size()){
      cout << left[i] << " ";
  }
  fd(i,(int)right.size()-1,0){
      cout << right[i] << " ";
  }
  cout << endl;
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

