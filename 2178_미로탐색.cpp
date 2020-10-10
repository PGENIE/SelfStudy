#include<iostream>
#include<vector>
#include<queue>;
#define WHITE 0
#define GRAY 1
#define BLACK 2

using namespace std;

typedef struct coord {
	int y;
	int x;
}coord;

int n, m;
queue<coord> q;
vector<vector<int>> map;
vector<vector<int>> color;
vector<vector<int>> cnt;

int x[4] = { 1,-1,0,0 };
int y[4] = { 0,0,1,-1 };

void bfs()
{
	int nexty, nextx, nowy, nowx;

	while (1)
	{
		if (q.size() == 0)
			break;
		nowy = q.front().y;
		nowx = q.front().x;
		q.pop();
		color[nowy][nowx] = BLACK;
		if (nowy == n && nowx == m)
		{
			break;
		}

		for (int i = 0; i < 4; i++)
		{
			nexty = nowy + y[i];
			nextx = nowx + x[i];

			if (nexty <= n && nextx <= m && nexty > 0 && nextx > 0)
			{
				if (map[nexty][nextx] == 1 && color[nexty][nextx] == WHITE)
				{
					q.push({ nexty,nextx });
					color[nexty][nextx] = GRAY;
					cnt[nexty][nextx] = cnt[nowy][nowx] + 1;
				}
			}
		}

	}
}

int main()
{
	cin >> n >> m;

	map.resize(n + 1, vector<int>(m + 1, 0));
	color.resize(n + 1, vector<int>(m + 1, 0));
	cnt.resize(n + 1, vector<int>(m + 1, 0));

	char tmp;
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < m + 1; j++)
		{
			cin >> tmp;
			map[i][j] = tmp - '0';
		}
		cin.get();
	}

	q.push({ 1,1 });
	cnt[1][1] = 1;
	bfs();

	cout << cnt[n][m];

	return 0;
}
