#include<iostream>
#include<vector>
#include<queue>

using namespace std;

typedef struct coord {
	int z;
	int y;
	int x;
}coord;

int m, n, h;
int red = 0;
int total = 0;
vector<vector<vector<int>>> map;
vector<vector<vector<int>>> days;
queue<coord> q;

//동. 서. 남. 북. 위. 아래
int y[6] = { 0,0,1,-1,0,0 };
int x[6] = { 1,-1,0,0,0,0 };
int z[6] = { 0,0,0,0,1,-1 };


int bfs()
{
	int nowz, nowy, nowx;
	int nextz, nexty, nextx;

	while (1)
	{
		//종료조건
		if (q.size() == 0)
		{
			return -1;
		}

		nowz = q.front().z;
		nowy = q.front().y;
		nowx = q.front().x;
		q.pop();

		for (int i = 0; i < 6; i++)
		{
			nextz = nowz + z[i];
			nexty = nowy + y[i];
			nextx = nowx + x[i];

			if (nextz < h && nextz >= 0 && nexty < n && nexty >= 0 && nextx < m && nextx >= 0)
			{
				if (map[nextz][nexty][nextx] == 0)
				{
					q.push({ nextz,nexty,nextx });
					map[nextz][nexty][nextx] = 1;
					red++;
					if (red == total)
						return days[nowz][nowy][nowx] + 1;

					days[nextz][nexty][nextx] = days[nowz][nowy][nowx] + 1;
				}
			}
		}
	}

}
int main()
{
	cin >> m >> n >> h;

	vector<vector<int>> minimap;
	minimap.resize(n, vector<int>(m, 0));

	map.resize(h, minimap);
	days.resize(h, minimap);

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				cin >> map[i][j][k];

				if (map[i][j][k] == 1)
				{
					q.push({ i,j,k });
					red++;
					total++;
				}
				else if (map[i][j][k] == 0)
					total++;
			}
		}
	}

	if (red == total)
	{
		cout << 0;
	}
	else
		cout << bfs();

	system("pause");

	return 0;
}