#include<iostream>
#include<math.h>

using namespace std;


int main()
{
	int n;
	int  cnt = 0;

	while (1)
	{
		cin >> n;
		
		if (n == 0)
			return 0;

		for (int i = n+1; i <= 2*n ; i++)
		{
			bool check = false;
			for (int j = 2; j <= sqrt(i); j++)
			{
				//i�� �Ҽ����� Ȯ��
				if (i % j == 0)
				{
					check = true;
					break;
				}
			}
			if (check == false)
				cnt++;
		}
		cout << cnt << "\n";

		cnt = 0;
	}
}
