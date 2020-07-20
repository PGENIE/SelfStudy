#include<iostream>

using namespace std;

int main()
{
	int a;

	cin >> a;

	//1
	//2~7
	//8~19
	//20
	//38

	/*
	a1 = 1;
	a2 = 2;
	an+1= an + 6(n-1)
	*/
	int cnt = 1;
	int start = 2;

	while (1)
	{
		if (a == 1)
		{
			cout << '0';
			return 0;
		}

		cnt++;
		start = start + (6 * cnt) - 6;

		if (a < start)
		{
			cout << cnt - 1;
			break;
		}


	}



	return 0;

}