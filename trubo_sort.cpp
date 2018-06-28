//BUBBLE SORT
#include<iostream>
using namespace std;
int main()
{
    int n;
    int *ar=NULL;
    cin>>n;
    ar=new int [n];
    for(int i=0;i<n;i++)
        cin>>ar[i];
    for(int i=0;i<n;i++)
        for(int j=0;j<n-1;j++)
        {
            if(ar[j]>ar[j+1])
            {
                int t;
                t=ar[j];
                ar[j]=ar[j+1];
                ar[j+1]=t;
            }
        }
    for(int i=0;i<n;i++)
        cout<<ar[i]<<endl;
}
