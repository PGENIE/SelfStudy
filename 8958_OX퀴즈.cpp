#include<iostream>

using namespace std;

int main()
{
	int n;

	cin >> n;

	char tmp;
	cin.get();
	for (int i = 0; i < n; i++)
	{
		int now = 0;
		int nowcnt = 0;
		int result = 0;

		while (1)
		{

			tmp = cin.get();

			if (tmp == '\n')
			{
				result += now;
				now = 0;
				break;
			}

			if (tmp == 'O')
			{
				nowcnt++;
				now += nowcnt;
			}
			else if (tmp == 'X')
			{
				result += now;
				now = 0;
				nowcnt = 0;
			}


		}
		cout << result << '\n';
		result = 0;
		now = 0;
	}



	return 0;
}