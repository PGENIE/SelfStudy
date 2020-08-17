#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

vector<vector<int>> building;
int k, n;

int howmany(int k, int n)
{
	int allBelow = 0;

	if (building[k][n] != 0)
		return building[k][n];

	
}
int main()
{
	int testCase;
	int t, i, j; 

	cin >> testCase;
	for (t = 0; t < testCase; t++)
	{	
		cin >> k >> n;
		building.resize(15, vector<int>(15,0)); //k´Â 0~k, nÀº 1~n »ç¿ë
		

		//Á© ¹Ø °¡·Î, Á© ¿ÞÂÊ ¼¼·Î °ª ±¸ÇÑ´Ù.
		for (j = 1; j <= n; j++)
		{
			building[0][j] = j;
		}
		for (i = 1; i <= k; i++)
		{
			building[i][1] = 1;
		}
		
		for (i = 1; i < k + 1; i++)
		{
			for (j = 2; j < n + 1; j++)
			{
				if (building[i][j] == 0)
				{
					int Below = building[i-1][j];

					building[i][j] = Below + building[i][j - 1];
				}
			}
		}
		cout << building[k][n] << "\n";
		building.clear();
	}
	return 0;
}

