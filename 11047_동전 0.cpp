#include<iostream>

using namespace std;

int n, k;

int main()
{
	int arr[10];

	int i, j;
	cin >> n >> k;

	for (i = 0 ; i < n ; i++)
	{
		cin >> arr[i];
	}
	
	int index = n - 1;
	int cnt = 0;
	while (1)
	{
		if (index < 0)
			break;

		if (k >= arr[index])
		{
			cnt += (k / arr[index]);
			k -= ((k / arr[index]) * arr[index]);
		}
		index--;
	}

	cout << cnt;

	return 0;
}