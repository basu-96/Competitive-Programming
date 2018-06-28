#include <cmath>
#include<string>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class people{
    int num;
    string name;
    public:
        void setnum(int a);
        void setname(string str);
        void display();
        bool compare(string str);
};
bool people :: compare(string str)
{
    if(str==name)
        return true;
        else
            return false;
}
 void people ::setnum(int a)
{
    num = a;
}
void people :: setname (string str)
{
    name = str;
}
void people :: display()
{
    cout<<name<<"="<<num<<endl;
}

int main()
{
    int n;
    people *ob=NULL;
    cin>>n;
    ob= new people[n];
    for(int i=0;i<n;i++)
    {
        int t;
        string str;
        cin>>str>>t;
        ob[i].setname(str);
        ob[i].setnum(t);
    }
    string str;
    while(cin>>str)
    {
        for(int i=0;i<n;i++)
        {
            if(ob[i].compare(str))
            {
                ob[i].display();
                break;
            }else if(!ob[i].compare(str) && i == n-1)
            {
                cout<<"Not found"<<endl;
            }

        }
    }
    return 0;
}
