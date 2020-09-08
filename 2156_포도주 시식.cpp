#include<iostream>
#include<algorithm>

using namespace std;

/*
1.한 칸 전에서 온 경우
두 칸 전 - 한칸 전 - 현재위치 는 불가능하므로, dp[n] = dp[n-i] + arr[i-1] + arr[i]; 이고 i는 3 이상 n 이하.
2. i칸 전에서 바로 온 경우 dp[n] = dp[n-i] + arr[i]; 이고 i는 2이상 n 이하
*/
int dp[10001] = { 0 };
int arr[10001];
int n;

int findMax(int n)
{
	if (n == 0)
		return 0;

	if (dp[n] != 0)
		return dp[n];

	int max1=0;
	int tmp;
	for (int i = 3; i <= n; i++)
	{
		tmp = findMax(n - i) + arr[n - 1] + arr[n];
		if (tmp > max1)
			max1 = tmp;
	}
	int max2 = 0;
	for (int i = 2; i <= n; i++)
	{
		tmp = findMax(n - i) + arr[n];

		if (tmp > max2)
			max2 = tmp;
	}

	dp[n] = max1 > max2 ? max1 : max2;

	return dp[n];
}
int main()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	dp[1] = arr[1];
	dp[2] = arr[1]+arr[2];

	for (int i = 0; i <= n; i++)
	{
		findMax(i);
	}

	int max = 0;
	for (int i = 0; i <= n; i++)
	{
		if (dp[i] > max)
			max = dp[i];
	}

	cout << max;

	return 0;
}