#include<iostream>

using namespace std;

long long tile[1000001] = { 0 }; //dp�� �ϱ����ؼ��� �����ϱ� ���� ��Ҹ� ���������Ѵ�! �Է°��� �� ���θ� ������! �鸸������ ������ �޸����� 256MB�� �Ȱɸ�. ������ ��ͷ� ��� ���� �޸��ʰ��� Ȯ�� ++;

long long dp(int n)
{
	//DP����Ʈ 1. �ʱ� RETURN�� ����
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;

	//DP����Ʈ 2. �ִ� ���̶�� Ȱ��
	if (tile[n] != 0) 
		return tile[n];

	//DP����Ʈ 3. ���� ���̶�� ��ͷ� �����ֱ�. ���� ���� Ȱ��ɶ�����.
	tile[n] = (dp(n - 1) + dp(n - 2))%15746;
	return tile[n];

}
int main()
{
	int n;
	cin >> n;

	//n��°�� ����: n-1��°���� 1�� ���� �� �ִ� ��� + n-2��°���� 00�� ���� �� �ִ� ���

	cout << dp(n);

	return 0;

}
