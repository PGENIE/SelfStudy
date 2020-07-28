#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	vector<int> cards(n,0);

	for (int i = 0; i < n; i++)
	{
		cin >> cards[i];
	}

	vector<int> coord(n, 0);

	for (int i = 0; i < 3; i++)
	{
		coord[n-1-i] = 1;
	}

	int max = 0;

	int sum;
	do {
		sum = 0;
		for (int i = 0; i < n; i++)
		{
			if (coord[i] == 1)
			{
				sum += cards[i];
			}
		}
		if (max < sum && sum <= m)
		{
			max = sum;
		}

	} while (next_permutation(coord.begin(), coord.end()));

	cout << max;

	return 0;
}

