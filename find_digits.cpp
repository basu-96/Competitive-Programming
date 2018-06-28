#include<iostream>
using namespace std;
int main()
{
   int t;
   int *s=NULL;
   cin>>t;
   s=new int[t];
   for(int i=0;i<t;i++)
   {
       int n,temp,c=0;
       cin>>n;
       temp=n;
       while(temp>0)
       {
           if(temp%10!=0&&(n%(temp%10)==0))
           {
               c++;
           }
           temp/=10;
       }
       s[i]=c;
   }
   for(int i=0;i<t;i++)
   {
       cout<<s[i]<<endl;
   }
}
