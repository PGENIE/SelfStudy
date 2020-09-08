#include<iostream>
#include<algorithm>

using namespace std;

/*
 나(i번째)를 밟는다고 가정
 = 한 칸 전에서 왔거나, 두 칸 전에서 왔거나
 //한 칸 전에서 왔다면? 연속 세 칸을 밟을 수는 없으므로 얘는 자신으로부터 두 칸 전에서 왔을 것이다.

 //따라서 
 //1. 세칸 전까지 최댓값 + 한칸 전의 값 + 나의 값 
 //2. 두칸전까지 최댓값 + 나의 값 이 됨.
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