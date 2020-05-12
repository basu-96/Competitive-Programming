#include<iostream>

using namespace std;

int main()
{
	int test_cases;
	cin >> test_cases;
	while(test_cases--)
	{
		int S, N;
		int flag = 0;
		cin >> N >> S;
		int *playerPrice = NULL;
		int *playerPos = NULL;
		playerPrice = new int [N];
		playerPos = new int [N];
		for(int i = 0; i < N; i++)
		{
			cin >> playerPrice[i];
		}
		for(int i = 0; i < N; i++)
		{
			cin >> playerPos[i];
		}
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{
				if(playerPos[i] != playerPos[j])
				{
					if(S+playerPrice[i]+playerPrice[j] <= 100) flag = 1;
				}
			}
		}
		if(flag) cout << "yes" << endl;
		else cout << "no" << endl;
	}

	return 0;
}