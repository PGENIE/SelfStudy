#include<iostream>
#include<math.h>

using namespace std;

int dp[1000001] = { 0 };
int x;

int find(int x)
{
	if (dp[x] != 0)
		return dp[x];

	int div3 = 1000000;
	int div2 = 1000000; 
	int min1 = 1000000;

	if (x % 3 == 0)
		div3 = find(x / 3) + 1;
	if (x % 2 == 0)
		div2 = find(x / 2) + 1;
	min1 = find(x - 1) + 1;

	//ÃÖ¼Ú°ª
	if (div3 < div2) {
		if (div3 < min1)
			dp[x] = div3;
		else
			dp[x] = min1;
	}
	else
	{
		if (div2 < min1)
			dp[x] = div2;
		else
			dp[x] = min1;
	}

	return dp[x];
}
int main()
{
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;

	cin >> x;
	int a;
	for (int i = 4; i <= x; i++)
	{
		a = find(x);
	}

	if (x <= 3)
		cout << dp[x];
	else
		cout << a;

	return 0;
}