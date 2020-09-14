#include<iostream>
#include<algorithm>

using namespace std;

int n;
int arr[1001];
int cnt[1001];

int main()
{

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		cnt[i] = 1;
	}
	int now = arr[1];
	int nowindex = 1;
	int max = 1;

	for (int i = 2; i <= n; i++)
	{
		if (now < arr[i])
		{
			cnt[i] = cnt[nowindex] + 1;
			now = arr[i];
			nowindex = i;
			max = cnt[i];
		}
	}

	cout << max;

	return 0;
	
}