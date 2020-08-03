#include<iostream>
#include<math.h>

using namespace std;

int main()
{
	int n;
	int result = 0;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;

		if (a == 1)
		{
			result++;
		}
		for (int j = 2; j <= sqrt(a); j++)
		{
			if (a % j == 0)
			{
				result++;
				break;
			}
		}

	}

	cout << n-result;

}

