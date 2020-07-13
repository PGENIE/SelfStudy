#include<iostream>

using namespace std;


int main()
{
	int a;
	int placeValueSum=0;
	int aRight=0;
	int sumRight=0;

	cin >> a;

	int first = a;
	int cnt = 0;

	while (1)
	{
		cnt++;

		if (a < 10)
		{
			aRight = a;
		}
		else
		{
			aRight = a % 10;
		}
		placeValueSum = (a / 10) + (a % 10);
		if (placeValueSum < 10)
		{
			sumRight = placeValueSum;
		}
		else
		{
			sumRight = placeValueSum % 10;
		}


		a = (aRight * 10) + (sumRight);

		if (a == first)
		{
			cout << cnt;
			break;
		}
			
	}

	return 0;
}