#include<iostream>

using namespace std;

int main()
{
	int a, b, v;
	int now = 0;
	int day = 0;

	cin >> a >> b >> v;

	if (v % (a - b) + (a - b) == a)
		cout << v / (a - b);

	else if (v % (a - b) != 0)
		cout << v / (a - b) + 1;

	else
		cout << v / (a - b) - 1;

	return 0;
}

/*
1. �����̰� ���� �� ���� ���
-����ġ�� �Ѱ��� ��
5 2 16
v%(a-b) != 0
cout << v/(a-b)+1;

- ����ġ�� �� ä���� ��
5 2 17

v%(a-b) + (a-b) == a �ΰ��� ������ + �� ��
cout << v/(a-b);


2. �����̰� ���� �� ������ ���� ���

cout << v / (a-b) + 1;

3 1 23

12��° �� ����
*/
