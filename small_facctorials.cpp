#include<iostream>
using namespace std;
class fact
{
    int m;
public:
    fact(){m=0;}
    void input();
    int cal();
};
void fact :: input()
{
    cin >>m;
}
int fact :: cal()
{
    int temp=1;
    for (int i=1;i<=m;i++)
        temp=temp*i;
    return temp;
}
int main()
{
    int n;
    fact *ob=NULL;
    cin>>n;
    ob = new fact[n];
    for (int i=0;i<n;i++)
        ob[i].input();
    for (int i=0;i<n;i++)
        cout<<ob[i].cal()<<endl;
  return 0;
}
