#include<iostream>
#include<algorithm>

using namespace std;

/*
 ��(i��°)�� ��´ٰ� ����
 = �� ĭ ������ �԰ų�, �� ĭ ������ �԰ų�
 //�� ĭ ������ �Դٸ�? ���� �� ĭ�� ���� ���� �����Ƿ� ��� �ڽ����κ��� �� ĭ ������ ���� ���̴�.

 //���� 
 //1. ��ĭ ������ �ִ� + ��ĭ ���� �� + ���� �� 
 //2. ��ĭ������ �ִ� + ���� �� �� ��.
*/

int dp[301] = { 0 };
int stair[301] = { 0 };
int main()
{
	int n;

	cin >> n;


	for (int i = 1; i <= n; i++)
	{
		cin >> stair[i];
	}

	dp[1] = stair[1];
	dp[2] = stair[1] + stair[2];

	for (int i = 3; i <= n; i++)
	{
		dp[i] = max(dp[i - 3] + stair[i - 1] + stair[i], dp[i - 2] + stair[i]);
	}

	cout << dp[n];

	return 0;
}