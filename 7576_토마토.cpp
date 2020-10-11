#include<iostream>
#include<vector>
#include<queue>
#define WHITE 0
#define GRAY 1
#define BLACK 2

using namespace std;

typedef struct coord {
	int y;
	int x;
}coord;

queue<coord> q;
vector<vector<int>> map;
vector<vector<int>> color;
vector<vector<int>> days;
int day = 0;
int n, m;
int red = 0;
int total = 0;

int x[4] = { 1,-1,0,0 };
int y[4] = { 0,0,1,-1 };

void bfs()
{
	int nowx, nowy;
	int nextx, nexty;

	while (1)
	{
		if (q.size() == 0 && total-red != 0)
		{
			cout << -1;
			return;
		}

		nowy = q.front().y; 
		nowx = q.front().x;

		q.pop();
		color[nowy][nowx] = BLACK;

		for (int i = 0; i < 4; i++)
		{
			nexty = nowy + y[i];
			nextx = nowx + x[i];

			if (nexty < n && nextx < m && nexty >= 0 && nextx >= 0)
			{
				if (map[nexty][nextx] == 0 && color[nexty][nextx] == WHITE)
				{
					q.push({ nexty, nextx });
					color[nexty][nextx] = GRAY;
					days[nexty][nextx] = days[nowy][nowx] + 1;
					red++;
				}
				if (total == red)
				{
					cout << days[nexty][nextx];
					return;
				}
			}
		}

	}
}
int main()
{
	cin >> m >> n;
	map.resize(n, vector<int>(m, 0));
	color.resize(n, vector<int>(m, 0));
	days.resize(n, vector<int>(m, 0));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 1)
			{
				red++;
				total++;
				q.push({i,j});
				color[i][j] == GRAY;
			}
			else if (map[i][j] == 0)
			{
				total++;
			}
		}
	}

	bfs();


	return 0;
}