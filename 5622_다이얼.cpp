#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
	char a[15];
	char tmp;
	int sum=0;

	while (1)
	{
		if ((tmp = cin.get()) == '\n')
			break;

		if (tmp <= 'C')
		{
			sum += 3;
		}
		else if (tmp <= 'F')
		{
			sum += 4;
		}
		else if (tmp <= 'I')
		{
			sum += 5;
		}
		else if (tmp <= 'L')
		{
			sum += 6;
		}
		else if (tmp <= 'O')
		{
			sum += 7;
		}
		else if (tmp <= 'S')
		{
			sum += 8;
		}
		else if (tmp <= 'V')
		{
			sum += 9;
		}
		else if (tmp <= 'Z')
		{
			sum += 10;
		}
	}

	cout << sum;
	



}