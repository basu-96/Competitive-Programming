#include<iostream>

using namespace std;

int main()
{
	int test_cases;
	cin >> test_cases;
	while(test_cases--)
	{
		long long int n, k = 0;
		cin >> n;
		while(n > 0)
		{
			n = n/5;
			k = k + n;
		}
		cout << k << endl;
	}
	return 0;
}