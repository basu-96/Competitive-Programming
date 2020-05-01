/*
https://www.codechef.com/MAY20B/problems/COVID19
*/
#include<bits/stdc++.h>

using namespace std;

int left_trav(int *pos, int i, int n)
{
	if (i == 0) return 0;
	int infected = 0;
	for(int j = i-1; -1 < j; j--)
	{
		int dist_diff = abs(pos[j]-pos[j+1]);
		if(dist_diff <= 2)
		{
			infected++;
		}
		else break;
	}
	return infected;
}
int right_trav(int *pos, int i, int n)
{
	if(i == n-1) return 0;
	int infected = 0;
	for(int j = i+1; j < n; j++)
	{
		int dist_diff = abs(pos[j-1]-pos[j]);
		if(dist_diff <= 2)
		{
			infected++;
		}
		else break;
	}
	return infected;
}

int main()
{
	int test_cases;
	cin >> test_cases;
	while(test_cases--)
	{
		int n;
		cin >> n;
		int min_inf = INT_MAX, max_inf = INT_MIN; 
		int *pos = NULL;
		pos = new int [n];
		for(int i = 0; i < n; i++)
		{
			cin >> pos[i];
		}
		for(int i = 0; i < n; i++)
		{
			int infected = 1;
			infected += left_trav(pos,i,n) + right_trav(pos,i,n);
			if (infected < min_inf) min_inf = infected;
			if (max_inf < infected) max_inf = infected;
		} 
		cout << min_inf << " " << max_inf << endl;
	}
	return 0;
}