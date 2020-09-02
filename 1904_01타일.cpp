#include<iostream>

using namespace std;

long long combi(int doubleZero, int one)
{
	int up = 1;
	int down = 1;
	int till;

	doubleZero < one ? till = doubleZero : till = one;

	for (int i = 0; i < till; i++)
	{
		up *= doubleZero + one - i;
		down *= till - i;
	}

	return up / down;
	
}
int main()
{
	//2��¥���� �� �� �ִ��� Ȯ���ؾ���.
	int n;

	cin >> n;

	//n�� ����, 2�� ���� �� �ִ� �ִ�ġ��ŭ �ְ� 1�� �ɲ��� -> 2 �Ѱ� �ٰ� 1 2�� �ø��� ... �̷�������. 
	//�迭�� �ڸ���ġ�ϱ�� �ϸ� �ɵ�. 1�� 3�� 2�� 5���� ġ�� 8C3�̳�.

	long long sum = 0;
	int doubleZero = n / 2; //�������ִ¸�ŭ �ִ�� ����.
	int one;

	if (n % 2 == 0)
		one = 0;
	else
		one = 1;

	while (1)
	{
		if (doubleZero == 0)
			break;

		sum += combi(doubleZero,one);
		one += 2;
		doubleZero -= 1;
	}
	sum += 1; //doubleZero == 0�� ����� ��

	cout << sum % 15746;

	return 0;

}
