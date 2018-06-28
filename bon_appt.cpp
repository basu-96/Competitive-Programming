#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<numeric>

using namespace std;

int main()
{
	int n, k;
	
	cin >> n >> k;
	vector<int> bills(n);	
	for (int i = 0; i < n; i++)
	{
		cin >> bills[i];
	}	
	int sum = accumulate(bills.begin(), bills.end(), 0.0);
	int cash;
	cin >> cash;
	if (cash == (sum - bills[k])/2)
	{
		cout << "Bon Appetit" << endl;
	}
	else
	{
		cout << cash - (sum - bills[k])/2 << endl;
	}

	return 0;
}
