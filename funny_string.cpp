/*https://www.hackerrank.com/challenges/funny-string*/
#include <cmath>
#include<cstring>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin>>t;
    char s[10001];
    while(t--)
    {
        cin>>s;
        int j = strlen(s);
        int d=1;
        for(int i=0;i<j-1;i++){
            if(!(abs(s[i+1]-s[i])==abs(s[j-i-1]-s[j-i-2]))){
                d = 0;
                break;
            }
        }
        if(d==0)
            cout<<"Not Funny"<<endl;
        else
            cout<<"Funny"<<endl;
    }
    return 0;
}

