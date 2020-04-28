#include<bits/stdc++.h>

using namespace std;

inline int getn(){
	int n=0, c = getchar_unlocked();
	while(c < '0' || c > '9')
	{
		c = getchar_unlocked();	
	} 
	while(c >= '0' && c <= '9')
	{		
		n = (n<<3) + (n<<1) + c - '0'; 
		c = getchar_unlocked();
	}
	return n;
}

int main()
{
	int test_cases;
	// test_cases = getn();
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		int n,x,y;
		int numFastcars;
		// n = getn();
		scanf("%d",&n);
		// x = getn();
		scanf("%d",&x);
		numFastcars = 1;
		for(int i = 0; i < n-1; i++)
		{
			// y = getn();
			scanf("%d",&y)
			cout << y << endl;
			if (y <= x)
			{
				numFastcars++;
				x = y;
			}
		}
		// cout << numFastcars << endl;
		printf("%d\n",numFastcars);
	}

	return 0;
}