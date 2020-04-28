#include<iostream>

using namespace std;

int main()
{
	int test_cases;
	cin >> test_cases;
	while(test_cases--)
	{
		int n,k;
		cin >> n >> k;
		cout << n % k << endl;
	}
	
	return 0;
}