#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> map;
vector<int> result;
int n;
int cnt = 0;
int x[4] = { 1,0,-1,0 }; //동쪽시작. 시계방향
int y[4] = { 0,1,0,-1 };

void dfs(int nowy, int nowx)
{
	cnt++;
	map[nowy][nowx] = 2;
	for (int i = 0; i < 4; i++)
	{
		int nexty = nowy + y[i];
		int nextx = nowx + x[i];

		if (nexty < n && nextx < n && nexty >= 0 && nextx >= 0 && map[nexty][nextx] == 1)
		{
			dfs(nexty, nextx);
		}
	}
}
int main()
{
	cin >> n;
	char tmp;
	map.resize(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> tmp;
			map[i][j] = tmp - '0';
		}
		cin.get();
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == 1)
			{
				dfs(i, j);
				result.push_back(cnt);
				cnt = 0;
			}
		}
	}

	sort(result.begin(), result.end());

	cout << result.size() << "\n";
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << "\n";
	}

	return 0;
}