#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	bool find = false;
	cin >> n;

	for (int i = n-54; i < n; i++)
	{
		int itmp=i;
		int result = 0;
		result += itmp;
		while (1)
		{
			result += itmp%10;
			itmp /= 10;

			if (itmp < 10)
			{
				result += itmp;
				break;
			}
			
		}
		if (result == n)
		{
			cout << i;
			find = true;
			return 0;
		}
	}
	if (find == false)
		cout << 0;

	return 0;
}
