#include<iostream>
#include<vector>

using namespace std;

int n;
long long dp[101][10];

int main()
{
	cin >> n;

	dp[1][0] = 0;
	for (int i = 1; i < 10; i++)
	{
		dp[1][i] = 1;
	}

	for (int i = 2; i <= n; i++)
	{
		dp[i][0] = dp[i - 1][1] % 1000000000;
		dp[i][9] = dp[i - 1][8] % 1000000000;
		for(int j = 1 ; j < 9 ;j ++)
		{
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
		}
	}

	long long result = 0;
	for (int i = 0; i <= 9; i++)
	{
		result += dp[n][i];
	}

	cout << result% 1000000000 << "\n";

	return 0;

}