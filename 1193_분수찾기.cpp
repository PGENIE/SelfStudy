#include<iostream>

using namespace std;

int main()
{
	int a;

	cin >> a;

	int cnt = 1;
	int sum = 0;

	while (1)
	{
		if (sum+cnt >= a)
			break;

		sum += cnt;
		cnt++;
	}

	int difference = a - sum;

	if (cnt % 2 == 0)
	{
		//����
		cout <<  difference;

		cout << '/';

		//�и�
		cout << cnt - difference + 1;
	}
	else
	{
		//����
		cout << cnt - difference + 1;;

		cout << '/';

		//�и�
		cout << difference;
	}


	return 0;

}

/*

1
12
321
1234
54321 (����. ¦����°���� ¦������ŭ ������� �Է�)


1
21
123
4321
12345 (�и�. Ȧ����°���� Ȧ������ŭ ������� �Է�)
*/

