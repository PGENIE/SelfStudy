#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> map;
vector<int> result;
int n, m, k;
int cnt = 0;
int x[4] = { 1,0,-1,0 }; //동쪽시작. 시계방향
int y[4] = { 0,1,0,-1 };

void dfs(int nowy, int nowx)
{
	map[nowy][nowx] = 2;
	for (int i = 0; i < 4; i++)
	{
		int nexty = nowy + y[i];
		int nextx = nowx + x[i];

		if (nexty < n && nextx < m && nexty >= 0 && nextx >= 0 && map[nexty][nextx] == 1)
		{
			dfs(nexty, nextx);
		}
	}
}
int main()
{
	int testCase, e;
	cin >> testCase;

	int x, y;
	for (int t = 0; t < testCase; t++)
	{
		cin >> m >> n >> k;
		map.resize(n, vector<int>(m, 0));
		for (int i = 0; i < k; i++)
		{
			cin >> x >> y;
			map[y][x] = 1;
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (map[i][j] == 1)
				{
					dfs(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << "\n";
		cnt = 0;
		map.clear();
	}


	return 0;
}