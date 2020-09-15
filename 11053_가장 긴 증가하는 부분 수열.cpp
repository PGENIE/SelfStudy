#include<iostream>

using namespace std;

int cnt[1001];
int arr[1001];
int n;

int main()
{
	int i, j;
	cin >> n;

	for (i = 1; i <= n; i++)
	{
		cin >> arr[i];
		cnt[i] = 1;
	}

	int tmpmax = 1;
	int max = 1;

	for (i = 2; i <= n; i++)
	{
		for (j = i - 1; j >= 1; j--)
		{
			if (arr[j] < arr[i] && cnt[j] >= tmpmax)
			{
				cnt[i] = cnt[j] + 1;
				tmpmax = cnt[i];
				if (max < tmpmax)
					max = tmpmax;
			}
		}
		tmpmax = 1;
	}
	
	cout << max;
	

	return 0;
}