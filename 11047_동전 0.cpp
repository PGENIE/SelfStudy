#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int n, k;
	int i, j;
	int arr[10];

	cin >> n >> k;

	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int cnt = 0;

	int a = k;
	while(1)
	{
		if (k == 0)
			break;

		for (i = 0; i < n; i++)
		{
			if (k - arr[i] < 0)
			{
				i--;
				break;
			}
			if (k - arr[i] == 0)
				break;
		}
			//i가 가장 큰 애
			cnt += k / arr[i];
			k %= arr[i];
	}

	cout << cnt;

	return 0;
}