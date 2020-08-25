#include<iostream>
#include<math.h>

using namespace std;

int main()
{
	int n;
	int cnt = 1;

	cin >> n;

	int i = 1;
	int now = 1;
	while (1)
	{
		if (n == 1)
		{
			cout << cnt;
			break;
		}

		if (now >= n)
		{
			cout << cnt;
			break;
		}


		now += (6 * i);
		i++;
		cnt++;

	}

	return 0;
}

