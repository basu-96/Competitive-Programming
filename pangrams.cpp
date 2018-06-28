/*https://www.hackerrank.com/challenges/pangrams*/
//ASCII for reference A=65...Z=90 a=97...z=122
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string.h>
#include<strings.h>
#include<cstring>
using namespace std;
int ar[26]={0};

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */


    char s[1001];


        int test = 0;
        cin>>s;
        int j = strlen(s);
        for(int i=0;i<j;i++)
        {
            if(s[i]<=90 && 65<=s[i])
            {
                ::ar[s[i]-65]=1;
            }
            else if(s[i]<=122 && 97<=s[i])
            {
                ::ar[s[i]-97]=1;
            }
        }
        for(int i =0;i<26;i++)
        {
            if(::ar[i]!=1)
                test = 1;
        }

        if(test==0)
        {
            cout<< "pangram"<<endl;
        }
        else
            cout<<"not pangram"<<endl;

    return 0;
}
