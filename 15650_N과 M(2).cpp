#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, m;



int main()
{
	cin >> n >> m;

	vector<int> coord(n, 0);
	vector<int> result;

	for (int i = 0; i < m; i++)
	{
		coord[n - i - 1] = 1;
	}

	do {

		for (int i = 0; i < n; i++)
		{
			if (coord[i] == 1)
			{
				result.push_back(i + 1);
			}
		}

	} while (next_permutation(coord.begin(), coord.end()));

	for (int i = result.size() - m; i >= 0; i -= m)
	{
		for (int j = 0; j < m; j++)
		{
			cout << result[i+j] << " ";
		}
		cout << "\n";
	}
	return 0;
}