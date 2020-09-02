#include<iostream>

using namespace std;

long long tile[1000001] = { 0 }; //dp를 하기위해서는 저장하기 위한 장소를 만들어놔야한다! 입력값을 잘 봐두면 좋을듯! 백만까지나 만들어두 메모리제한 256MB에 안걸림. 오히려 재귀로 계속 들어가면 메모리초과될 확률 ++;

long long dp(int n)
{
	//DP포인트 1. 초기 RETURN값 설정
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;

	//DP포인트 2. 있는 값이라면 활용
	if (tile[n] != 0) 
		return tile[n];

	//DP포인트 3. 없는 값이라면 재귀로 돌려주기. 이전 값들 활용될때까지.
	tile[n] = (dp(n - 1) + dp(n - 2))%15746;
	return tile[n];

}
int main()
{
	int n;
	cin >> n;

	//n번째의 입장: n-1번째에서 1을 넣을 수 있는 경우 + n-2번째에서 00을 넣을 수 있는 경우

	cout << dp(n);

	return 0;

}
