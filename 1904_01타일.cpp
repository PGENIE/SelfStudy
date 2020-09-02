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
	//2개짜리가 몇 개 있는지 확인해야함.
	int n;

	cin >> n;

	//n을 보고, 2를 넣을 수 있는 최대치만큼 넣고 1은 쪼끔만 -> 2 한개 줄고 1 2개 늘리고 ... 이런식으로. 
	//배열은 자리배치하기로 하면 될듯. 1이 3개 2가 5개라 치면 8C3이네.

	long long sum = 0;
	int doubleZero = n / 2; //가질수있는만큼 최대로 가짐.
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
	sum += 1; //doubleZero == 0인 경우의 수

	cout << sum % 15746;

	return 0;

}
