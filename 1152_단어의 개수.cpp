#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
	//a �� 97����, A�� 65����
	
	int cnt = 0;
	char tmp;
	bool end = false;
	
	while (1)
	{
		if (end == true || ((tmp = cin.get()) == '\n'))
			break;


		if ((tmp >= 'a' && tmp <= 'z') || (tmp >= 'A' && tmp <= 'Z'))
		{
			cnt++;

			while (1)
			{
				tmp = cin.get();
				if (tmp == '\n' || tmp == ' ')
				{
					if (tmp == '\n')
						end = true;
					break;
				}
			}
		}

	}

	cout << cnt;

}