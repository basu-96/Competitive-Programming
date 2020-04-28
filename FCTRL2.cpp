#include<iostream>
#include<vector>

using namespace std;


int main()
{
	int test_cases;
	cin >> test_cases;
	while(test_cases--)
	{
		int n;
		cin >> n;
		vector<int> prod(1000,1);
		int m,carry;
		carry = 0; m = 0;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 0; j <= m; j++)
			{
				prod[j] = prod[j]*i + carry;
				carry = prod[j] / 10;
				prod[j] = prod[j] % 10;
			}
			while(carry)
			{
				m++;
				prod[m] = carry % 10;
				carry = carry / 10;
			}
		}
		for(int i = m; i >= 0; i--)
		{
			cout << prod[i];
		}
		cout << endl;
	}

	return 0;
}