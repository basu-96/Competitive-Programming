//Problem link - https://www.codechef.com/JULY20B/problems/ADAKING

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
    int n,i,j;
    int prev_x, prev_y, last_x, last_y=-INT_MAX;
    cin >> n;
    char pos[8][8];
    vector<vector<int>> v(8);
    rep(i,8){
        rep(j,8){
            pos[i][j] = '.';
        }
    }
    pos[0][0] = 'O';
    if(n == 64){
        goto here1;
    }
    prev_x = 0;
    prev_y = 0;
    rep(i,8){
        prev_x = i;
        rep(j,8){
            prev_y = j;
            if(n==0){
                last_x = i;
                //cout << i << endl;
                goto here;
            }
            if(pow(prev_x-i,2)+pow(prev_y-j,2) <= 2){
                //cout << i << " " << j << endl;
                n--;
                v[i].push_back(j);
            }
        }
        //v.push_back(prev_y);
    }
here:
    rep(i,8){
        int size = (int)v[i].size();
        if(size!=0){
            //cout << size << endl;
            last_y = size;
            if(v[i][size-1]+1 < 8){
                pos[i][v[i][size-1]+1] = 'X';
            }
        }
    }
    //cout <<"last_x = " << last_x << endl;
    if(last_y == 8){
        f(i,last_x,8){
            f(j,0,8){
                pos[i][j] = 'X';
            }
        }
    }else{
        f(j,last_y,8){
            pos[last_x][j] = 'X';
        }
        f(i,last_x+1,8){
            rep(j,8){
                pos[i][j] = 'X';
            }
        }
    }
here1:
    rep(i,8){
        rep(j,8){
            cout << pos[i][j];
        }
        cout << "\n";
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
