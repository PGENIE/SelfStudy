#include<iostream>

using namespace std;


int main()
{
	
	int n;
	cin >> n;

	if (n < 100)
	{
		cout << n;
	}
	else
	{
		int result = 99;
		for (int i = 100; i <= n; i++)
		{
			int digit = i;
			int units = 0;
			int tens = 0;
			int hundreds = 0;

			if (i == 1000)
				break;

			units = digit % 10;
			digit /= 10;
			tens = digit % 10;
			digit /= 10;
			hundreds = digit % 10;

			if (units - tens == tens - hundreds)
			{
				result += 1;
			}

		}
		cout << result;
	}

	return 0;

}