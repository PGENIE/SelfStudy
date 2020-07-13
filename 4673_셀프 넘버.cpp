#include<iostream>

using namespace std;


int main()
{
	
	bool arr[10001] = { false };


	for (int i = 1; i <= 10000; i++)
	{
		int digit = i;
		int sum = 0;

		sum += digit;

		while (1)
		{
			if (digit == 0)
				break;

			sum += digit % 10;
			digit /= 10; 

		}

		if(sum <= 10000)
			arr[sum] = true;


	}

	for (int i = 1; i <= 10000; i++)
	{
		if (arr[i] == false)
			cout << i << "\n";
	}

	return 0;

}