#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main()
{

	int n, m;

	cin >> n >> m;

	vector<int> coord(n,0);

	for (int i = 0; i < m; i++)
	{
		coord[n - 1 - i] = 1;
	}

	do {
		for (int i = 0; i < n; i++)
		{
			if (coord[i] == 1)
			{
				cout << i + 1 << " ";
			}
		}
		printf("\n");
	} while (next_permutation(coord.begin(), coord.end()));



	return 0;

}
//아 이게 순열문젠데 조합이라고 생각하고 풀었네...

