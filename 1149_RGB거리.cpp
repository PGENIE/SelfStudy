#include<iostream>
#include<algorithm>

using namespace std;

int house[1001][3];
int dp[1001][3] = { 9999 };

int main()
{
	//이틀전 코드 나처럼 풀면 예외상황이 발생한다!!
	//DP생각 : 지금 나는 과거의것들을 통해 나올 수 있는 값이다!
	//지금 나까지의 최소비용 = 이전 다른색 값 + 나 값  OR 이전 다른다른색 값 + 나 값     둘 중에 최솟값.
	//i번째 빨강의 최소비용 = i-1번째 초록 . i-1번째 파랑 중 작은 것을 골라야함.

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