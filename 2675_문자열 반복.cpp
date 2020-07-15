#include<iostream>

using namespace std;

int main()
{
	int testCase;

	cin >> testCase;

	for (int i = 0 ; i < testCase; i++)
	{
		int count;

		cin >> count;

		char tmp;

		tmp = cin.get(); //ฐ๘น้

		while (1)
		{
			if ((tmp = cin.get()) == '\n')
			{
				break;
			}

			for (int j = 0; j < count; j++)
			{
				cout << tmp;
			}

		}
		cout << "\n";
	}


}