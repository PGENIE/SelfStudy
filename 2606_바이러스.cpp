#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> map;
int n, m;
int cnt = 0;
int color[101] = { 0 };

void dfs(int start)
{
	color[start] = 1;
	cnt++;

	for (int i = 1; i < n + 1; i++)
	{
		if (map[start][i] == 1 && color[i] == 0)
		{
			color[i] = 1;
			dfs(i);
		}

	}
}

int main()
{
	int x, y;
	cin >> n >> m;

	map.resize(n + 1, vector<int>(n + 1, 0));

	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		map[x][y] = 1;
		map[y][x] = 1;
	}

	dfs(1);
	cout << cnt - 1;

	return 0;
}