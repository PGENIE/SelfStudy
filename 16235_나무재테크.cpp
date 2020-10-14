#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct tree {
	int y;
	int x;
	int age;
}tree;

int n, m, k;
vector<vector<vector<int>>> map; //나무정보
vector<vector<int>> ground; //양분정보
vector<vector<int>> add; //양분정보
vector<tree> dieList;
vector<tree> fallList;

void spring()
{
	int i, j, a;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			for (a = 0; a < map[i][j].size(); a++)
			{
				if (ground[i][j] < map[i][j][a])
				{
					int sizeSave = map[i][j].size();
					for (int tmp = a; tmp < sizeSave; tmp++)
					{
						dieList.push_back({ i,j,map[i][j][a] });
						map[i][j].erase(map[i][j].begin() + a);
					}
				}
				else
				{
					ground[i][j] -= map[i][j][a];
					map[i][j][a]++;
					if (map[i][j][a] % 5 == 0)
					{
						fallList.push_back({ i,j,map[i][j][a] });
					}
				}
			}
		}
	}
}
void summer()
{
	int dieY;
	int dieX;
	int dieAge;
	for (int i = 0; i < dieList.size(); i++)
	{
		dieY = dieList[i].y;
		dieX = dieList[i].x;
		dieAge = dieList[i].age / 2;
		ground[dieY][dieX] += dieAge;
	}
	dieList.clear();
}
void fall()
{
	//북쪽부터 시계방향으로 한 바퀴
	int x[8] = { 0,1,1,1,0,-1,-1,-1 };
	int y[8] = { -1,-1,0,1,1,1,0,-1 };
	int nowy, nowx;
	int nexty, nextx;

	for (int i = 0; i < fallList.size(); i++)
	{
		nowy = fallList[i].y;
		nowx = fallList[i].x;
		for (int j = 0; j < 8; j++)
		{
			nexty = nowy + y[j];
			nextx = nowx + x[j];

			if (nexty <= n && nexty >= 1 && nextx <= n && nextx >= 1)
			{
				map[nexty][nextx].push_back(1);
			}
		}
	}
	fallList.clear();

}
void winter()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			ground[i][j] += add[i][j];
		}
	}
}

int main()
{
	int i, j;

	cin >> n >> m >> k;
	map.resize(n + 1, vector<vector<int>>(n + 1, vector<int>(0)));
	ground.resize(n + 1, vector<int>(n + 1, 0));
	add.resize(n + 1, vector<int>(n + 1, 0));

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			ground[i][j] = 5;
		}
	}

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			cin >> add[i][j];
		}
		cin.get();
	}

	int y, x, z;
	for (i = 0; i < m; i++)
	{
		cin >> y >> x >> z;
		map[y][x].push_back(z);
	}


	for (int year = 0; year < k; year++)
	{
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				sort(map[i][j].begin(), map[i][j].end());
			}
		}

		spring();
		summer();
		fall();
		winter();
	}

	int treeCnt = 0;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			treeCnt += map[i][j].size();
		}
	}
	cout << treeCnt;

	system("pause");

	return 0;

}