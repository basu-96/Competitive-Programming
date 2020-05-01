/*
https://www.codechef.com/MAY20B/problems/CORUS
*/

#include<bits/stdc++.h>

using namespace std;

int main()
{
	int test_cases;
	cin >> test_cases;
	while(test_cases--)
	{
		int num_str, num_queries;
		cin >> num_str >> num_queries;
		string str;
		cin >> str;
		vector<int> count(26,0);
		for(int i = 0; i < num_str; i++)
		{
			count[str[i]-'a']++;
		}
		for(int i = 0; i < num_queries; i++)
		{
			int num_iso, num_queue = 0;
			cin >> num_iso;
			for(int j = 0; j < 26; j++)
			{
				if (num_iso < count[j]) num_queue += count[j] - num_iso; 
			}
			cout << num_queue << endl;
		}
	}
	return 0;
}