#include<iostream>

using namespace std;

int n;
int arr[100001];
int dp[100001];
bool changeZero[100001] = { false };

int main()
{
	int i, j;

	cin >> n;

	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
		dp[i] = arr[i];
	}

	int max = arr[0];

	for (i = 1; i < n; i++)
	{
		if (dp[i - 1] > 0)
		{
			dp[i] = dp[i - 1] + arr[i];
			if (max < dp[i])
				max = dp[i];
		}
		else
		{
			if (dp[i] > dp[i - 1] && max < dp[i])
				max = dp[i];
		}
	
	}

	cout << max;

	return 0;

	
}