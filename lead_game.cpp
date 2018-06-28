#include<iostream>
using namespace std;
int main()
{
    int n,lead=0,w;
    int s1;
    int s2;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>s1;
        cin>>s2;
        if(s1>s2)
        {
            if(lead<s1-s2)
            {
                w=1;
                lead=s1-s2;
            }
        }
        else if(s2>s1)
        {
            if(lead<s2-s1)
            {
                w=2;
                lead=s2-s1;
            }
        }
        else if(s2==s1)
        {

            continue;
        }
    }
    cout<<w<<" "<<lead;
}
