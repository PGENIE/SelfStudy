#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int sixCnt = 0;//단, 6이 연속되어야 함!

	int n;
	cin >> n;

	int cnt = 1;
	int now = 667;
	int num = now;
	while (1)
	{
		if (cnt == n)
			break;

		num = now;

		while (1)
		{
			if (num < 10)
			{
				if (sixCnt == 2 && num == 6)
					sixCnt++;
				else
					break;
			}

			if (sixCnt >= 3)
				break;


			if (num % 10 == 6)
			{
				sixCnt++;
			}
			else if (sixCnt != 0 && num % 10 != 6)
			{
				sixCnt = 0;
			}

			num /= 10;

		}
		if (sixCnt >= 3)
			cnt++;
		now++;
		sixCnt = 0;
	}
	cout << now-1;
}
