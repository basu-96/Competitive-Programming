#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int test_cases;
    cin >> test_cases;
    while(test_cases--){
      string str;
      cin >> str;
      int ans = 0;
      int n = str.size();
      int i = 0;
      do{
          if(str[i]=='x'){
            if(str[i+1]=='y'){
            ans+=1;
            i+=2;
            }else{
            i+=1;
            }
          }else{
            if(str[i+1]=='x'){
            ans+=1;
            i+=2;
            }else{
            i+=1;
            }
            }
      }while(i<n);
     cout << ans << endl;
      ans = 0;
    }
    return 0;
}
