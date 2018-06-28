#include <iostream>//ASCII code ref- a:97.......z:122; A:65......Z:90

using namespace std;

int main()
{
  int n,k;
    char str[101];
    cin>>n>>str>>k;
    k %= 26;
    for (int i=0;i<n;i++)
    {
        if (str[i]>='A' && str[i]<='Z')
            str[i] = (str[i]-'A'+k)%26+'A';
        else if (str[i]>='a' && str[i]<='z')
            str[i] = (str[i]-'a'+k)%26+'a';
    }
    cout<<str;
    return 0;
}
