#include<iostream>
using namespace std;
int main()
{
    int n,s;
    cin>>n;
    if(n<3)
        {cout<<-1<<endl;}
    else
    {int *a=NULL;
        a =new int[n];
        for(int i=0;i<n;i++)
        {
            if((n-5*i)%5==0)
            {   s=i;

                for(int i=0;i<n;i++)
                {
                    if(i<s)
                        a[i]=5;
                    else
                        a[i]=3;
                }
                for(int i=0;i<n;i++)
                    cout<<a[i];
                cout<<endl;
            }
        }
    }
}
