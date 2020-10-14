#include<iostream>
#include<vector>

using namespace std;

typedef struct coord {
	int y;
	int x;
}coord;
typedef struct dirt {
	int y;
	int x;
	int amount;
}dirt;
vector<vector<int>> map;
vector<coord> machine;
vector<dirt> dirts;
int r, c, t;
int x[4] = { 1,-1,0,0 };
int y[4] = { 0,0,1,-1 };

void dirtMove()
{
	for (int i = 0; i < dirts.size(); i++)
	{
		int nowy, nowx, nowAmount;
		int nexty, nextx;
		int nextCnt = 0;

		nowy = dirts[i].y;
		nowx = dirts[i].x;
		nowAmount = dirts[i].amount;
		int addAmount = nowAmount / 5;

		for (int d = 0; d < 4; d++)
		{
			nexty = nowy + y[d];
			nextx = nowx + x[d];

			if (nexty < r && nextx < c && nexty >= 0 && nextx >= 0)
			{
				if (map[nexty][nextx] != -1)
				{
					nextCnt++;
					map[nexty][nextx] += addAmount;
				}
			}
		}
		int minusAmount = nextCnt * addAmount;
		map[nowy][nowx] -= minusAmount;
		nextCnt = 0;

	}
	dirts.clear();
}
void machineUp()
{
	int my = machine[0].y;
	int mx = machine[0].x;

	map[my - 1][mx] = 0;

	int nowy = my - 1;
	int nowx = mx;


	while (1)//밑으로이동
	{
		if (nowy <= 0)
			break;

		map[nowy][nowx] = map[nowy - 1][nowx];
		nowy--;
	}
	nowy = 0; nowx = 0;
	while (1)//왼쪽이동
	{
		if (nowx >= c - 1)
			break;
		map[nowy][nowx] = map[nowy][nowx + 1];
		nowx++;
	}
	nowy = 0; nowx = c - 1;
	while (1)//위로이동
	{
		if (nowy >= my)
			break;
		map[nowy][nowx] = map[nowy + 1][nowx];
		nowy++;
	}
	nowy = my; nowx = c - 1;
	while (1)//오른쪽으로이동
	{
		if (nowx <= 1)
			break;
		map[nowy][nowx] = map[nowy][nowx - 1];
		nowx--;
	}
	map[my][mx + 1] = 0;

	return;
}
void machineDown()
{
	int my = machine[1].y;
	int mx = machine[1].x;

	map[my + 1][mx] = 0;

	int nowy = my + 1;
	int nowx = mx;

	while (1)//위로이동
	{
		if (nowy >= r - 1)
			break;
		map[nowy][nowx] = map[nowy + 1][nowx];
		nowy++;
	}

	nowy = r - 1; nowx = 0;
	while (1)//왼쪽이동
	{
		if (nowx >= c - 1)
			break;
		map[nowy][nowx] = map[nowy][nowx + 1];
		nowx++;
	}

	nowx = c - 1; nowy = r - 1;
	while (1)//밑으로이동
	{
		if (nowy <= my)
			break;

		map[nowy][nowx] = map[nowy - 1][nowx];
		nowy--;
	}

	nowy = my; nowx = c - 1;
	while (1)//오른쪽으로이동
	{
		if (nowx <= 1)
			break;
		map[nowy][nowx] = map[nowy][nowx - 1];
		nowx--;
	}
	map[my][1] = 0;

	return;

}
int main()
{
	int i, j;

	cin >> r >> c >> t;
	map.resize(r, vector<int>(c, 0));
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == -1)
				machine.push_back({ i,j });
			else if (map[i][j] != 0)
				dirts.push_back({ i,j,map[i][j] });

		}
	}

	for (int time = 0; time < t; time++)
	{
		dirtMove();
		machineUp();
		machineDown();
		for (i = 0; i < r; i++)
		{
			for (j = 0; j < c; j++)
			{
				if (map[i][j] != 0 && map[i][j] != -1)
					dirts.push_back({ i,j,map[i][j] });

			}
		}
	}

	int result = 0;
	for (i = 0; i < dirts.size(); i++)
	{
		result += dirts[i].amount;
	}
	cout << result;

	system("pause");

	return 0;
}
