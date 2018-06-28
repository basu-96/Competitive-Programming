#include<iostream>
using namespace std;
int main()
{
    int t,n,k;
    int q[1000];
    cin>>t;
    for(int i=0;i<1000;i++)
        q[i]=0;
    string s[10];
    for(int i=0;i<t;i++)
    {
        cin>>n>>k;int ky=0;
        for(int j=0;j<n;j++)
        {
            cin>>q[j];
            if(q[j]<=0)
                ky++;
        }
        if(ky>=k)
            s[i]="NO";
        else
            s[i]="YES";
    }
    for(int i=0;i<t;i++)
        cout<<s[i]<<endl;
}
