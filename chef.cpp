#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int t=0;
    vector<int> input;
    while(t!=42)
    {
        cin>>t;
        if(t!=42)
        {
           input.push_back(t);
        }

    }
    for(int i=0; i < input.size(); i++)
           {
               cout << input[i] << endl;
           }
    return 0;
}
