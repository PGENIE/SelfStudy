#include<iostream>
#include<algorithm>

using namespace std;

int house[1001][3];
int dp[1001][3] = { 9999 };

int main()
{
	//��Ʋ�� �ڵ� ��ó�� Ǯ�� ���ܻ�Ȳ�� �߻��Ѵ�!!
	//DP���� : ���� ���� �����ǰ͵��� ���� ���� �� �ִ� ���̴�!
	//���� �������� �ּҺ�� = ���� �ٸ��� �� + �� ��  OR ���� �ٸ��ٸ��� �� + �� ��     �� �߿� �ּڰ�.
	//i��° ������ �ּҺ�� = i-1��° �ʷ� . i-1��° �Ķ� �� ���� ���� ������.

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> house[i][j];
		}
		cin.get();
	}

	dp[0][0] = house[0][0];
	dp[0][1] = house[0][1];
	dp[0][2] = house[0][2];

	for (int i = 1; i < n; i++)
	{
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + house[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + house[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + house[i][2];
	}
	
	if (dp[n - 1][0] < dp[n - 1][1])
	{
		if (dp[n - 1][0] < dp[n - 1][2])
			cout << dp[n - 1][0];
		else
			cout << dp[n-1][2];
	}
	else
	{
		if (dp[n - 1][1] < dp[n - 1][2])
			cout << dp[n - 1][1];
		else
			cout << dp[n-1][2];
	}
	return 0;
}