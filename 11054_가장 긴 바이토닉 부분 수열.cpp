#include<iostream>

using namespace std;

int main()
{
	int n;
	int arr[1001];
	int increase[1001];
	int decrease[1001];
	int  i, j;

	cin >> n;

	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
		increase[i] = 1;
		decrease[i] = 1;
	}

	//increase와 decrease구하기
	int index = 0;
	int max = 1;
	int min = 1;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < i; j++)
		{
			if(arr[j] < arr[i] && increase[j] >= max)
			{
				max = increase[j];
				increase[i] = max+1;
			}
		}
		max = 1;
		
		for (j = n - 1; j > n - 1 - i; j--)
		{
			if (arr[n - i - 1] > arr[j] && decrease[j] >= max)
			{
				max = decrease[j];
				decrease[n-i-1] = max + 1;
			}
		}
		max = 1;
	}
	
	int result = 0;
	int tmpresult = 0;
	bool find = false;
	max = 1;
	//순차적으로 확인하기. i번째가 최댓값이라고 한다면?
	for (i = 0; i < n; i++)
	{
		result = increase[i];
		for (j = i + 1; j < n; j++)
		{
			if (arr[i] > arr[j] && decrease[j] >= max)
			{
				max = decrease[j];
				find = true;
			}
		}
		if (find == true)
		{
			result += max;
			find = false;
		}
		if (result > tmpresult)
		{
			tmpresult = result;
		}
		max = 1;
	}

	cout << tmpresult;
	return 0;
}