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
		//분자
		cout <<  difference;

		cout << '/';

		//분모
		cout << cnt - difference + 1;
	}
	else
	{
		//분자
		cout << cnt - difference + 1;;

		cout << '/';

		//분모
		cout << difference;
	}


	return 0;

}

/*

1
12
321
1234
54321 (분자. 짝수번째마다 짝수번만큼 순서대로 입력)


1
21
123
4321
12345 (분모. 홀수번째마다 홀수번만큼 순서대로 입력)
*/

