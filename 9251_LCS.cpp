#include<iostream>

using namespace std;

char arr1[1001];
char arr2[1001];

int main()
{
	int k, i, j;
	char tmp;
	int arr1size;
	int arr2size;

	for (i = 0; i < 1001; i++)
	{
		tmp = cin.get();
		if (tmp == '\n')
		{
			arr1size = i;
			break;
		}
		arr1[i] = tmp;
	}

	for (i = 0; i < 1001; i++)
	{
		tmp = cin.get();
		if (tmp == '\n')
		{
			arr2size = i;
			break;
		}
		arr2[i] = tmp;
	}
	
	int maxcnt = 0;
	int cnt = 0;
	int index2 = 0;

	for(k = 0 ; k < arr1size; k++)
	{
		cnt = 0;
		index2 = 0;
		for (i = k; i < arr1size; i++)
		{
			for (j = index2; j < arr2size; j++)
			{
				if (arr1[i] == arr2[j])
				{
					index2 = j+1;
					cnt++;
					break;
				}
			}
		}
		if (maxcnt < cnt)
			maxcnt = cnt;
	}

	cout << maxcnt;
	

	
}