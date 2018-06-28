#include<iostream>
using namespace std;
class holes
{
    int c;
    char ch[40];
public:
    holes(){c=0;}
    void input();
    int count_hole();
};

void holes::input()
{
    cin>>ch;
}
int holes ::count_hole()
{
    int i = 0;
    while(ch[i]!= '\0')
       {
         if(ch[i]== 'A'||ch[i]=='D'||ch[i]=='O'||ch[i]=='P'||ch[i]=='Q'||ch[i]=='R'||ch[i]=='S')
        {
            c++;
        }
        else if(ch[i] == 'B')
        {
            c+=2;
        }
        i++;
       }
   cout << c<<endl;

}
int main()
{
    int n;
    holes* ob=NULL;
    cin >>n;
    ob = new holes [n];
    for(int i=0;i<n; i++)
    {
        ob[i].input();
    }
    for (int i=0;i<n;i++)
    {
        ob[i].count_hole();
    }
delete []ob;
}


