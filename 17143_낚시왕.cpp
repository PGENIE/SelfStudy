#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct shark {
	int speed;
	int direction;
	int size;
}shark;

typedef struct sharkinfo {
	int y;
	int x;
	int speed;
	int direction;
	int size;
}sharkinfo;

vector<vector<vector<shark>>> map;
vector<sharkinfo> sharks;
int r, c, m;
int fisherLocation = 1;
int fishSum = 0;

bool comp(const shark& x, const shark& y)
{
	return x.size < y.size;
}

void catchFish(int now)
{
	for (int i = 1; i <= r; i++)
	{
		if (map[i][now].size() != 0)
		{
			fishSum += map[i][now][0].size;
			map[i][now].erase(map[i][now].begin());
			for (int j = 0; j < sharks.size(); j++)
			{
				if (sharks[j].y == i && sharks[j].x == now)
				{
					sharks.erase(sharks.begin() + j);
					break;
				}
			}
			break;
		}
	}
	return;
}
void sharkMove()
{
	int move;
	for (int i = 0; i < sharks.size(); i++)
	{
		int originy = sharks[i].y;
		int originx = sharks[i].x;

		if (sharks[i].direction == 1 || sharks[i].direction == 2)
		{
			move = sharks[i].speed % ((r - 1) * 2);
		}
		else
			move = sharks[i].speed % ((c - 1) * 2);

		if (sharks[i].direction == 1) // 위 아래 오른 왼쪽
		{
			while (1)
			{
				while (1)
				{
					if (sharks[i].y == 1 || move == 0)
						break;

					sharks[i].y--;
					sharks[i].direction = 1;
					move--;
				}
				if (move == 0)
					break;


				while (1)
				{
					if (sharks[i].y == r || move == 0)
						break;

					sharks[i].y++;
					sharks[i].direction = 2;
					move--;
				}
				if (move == 0)
					break;


				while (1)
				{
					if (sharks[i].y == 1 || move == 0)
						break;

					sharks[i].y--;
					sharks[i].direction = 1;
					move--;
				}
				if (move == 0)
					break;
			}
		}
		if (sharks[i].direction == 2)
		{
			while (1)
			{
				while (1)
				{
					if (sharks[i].y == r || move == 0)
						break;

					sharks[i].y++;
					sharks[i].direction = 2;
					move--;
				}
				if (move == 0)
					break;

				while (1)
				{
					if (sharks[i].y == 1 || move == 0)
						break;

					sharks[i].y--;
					sharks[i].direction = 1;
					move--;
				}
				if (move == 0)
					break;


				while (1)
				{
					if (sharks[i].y == r || move == 0)
						break;

					sharks[i].y++;
					sharks[i].direction = 2;
					move--;
				}
				if (move == 0)
					break;



			}
		}
		if (sharks[i].direction == 3)
		{
			while (1)
			{
				while (1)
				{
					if (sharks[i].x == c || move == 0)
						break;

					sharks[i].x++;
					sharks[i].direction = 3;
					move--;
				}
				if (move == 0)
					break;

				while (1)
				{
					if (sharks[i].x == 1 || move == 0)
						break;

					sharks[i].x--;
					sharks[i].direction = 4;
					move--;
				}
				if (move == 0)
					break;

				while (1)
				{
					if (sharks[i].x == c || move == 0)
						break;

					sharks[i].x++;
					sharks[i].direction = 3;
					move--;
				}
				if (move == 0)
					break;
			}
		}
		if (sharks[i].direction == 4)
		{
			while (1)
			{
				while (1)
				{
					if (sharks[i].x == 1 || move == 0)
						break;

					sharks[i].x--;
					sharks[i].direction = 4;
					move--;
				}
				if (move == 0)
					break;

				while (1)
				{
					if (sharks[i].x == c || move == 0)
						break;

					sharks[i].x++;
					sharks[i].direction = 3;
					move--;
				}
				if (move == 0)
					break;

				while (1)
				{
					if (sharks[i].x == 1 || move == 0)
						break;

					sharks[i].x--;
					sharks[i].direction = 4;
					move--;
				}
				if (move == 0)
					break;
			}
		}

		map[originy][originx].erase(map[originy][originx].begin());
		map[sharks[i].y][sharks[i].x].push_back({ sharks[i].speed, sharks[i].direction, sharks[i].size });
	}

	sharks.clear();
}
void sharkEat()
{
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			if (map[i][j].size() >= 2)
			{
				sort(map[i][j].begin(), map[i][j].end(), comp);
				shark biggest;
				biggest = map[i][j][map[i][j].size() - 1];
				map[i][j].clear();
				map[i][j].push_back(biggest);
			}
		}
	}
	return;
}
int main()
{
	cin >> r >> c >> m;
	vector<vector<shark>> minimap;
	minimap.resize(c + 1, vector<shark>());
	map.resize(r + 1, minimap);

	int sharky, sharkx;
	int s, d, z;
	shark tmp;
	for (int i = 0; i < m; i++)
	{
		cin >> sharky >> sharkx >> s >> d >> z;
		tmp.speed = s;
		tmp.direction = d;
		tmp.size = z;
		map[sharky][sharkx].push_back(tmp);
		sharks.push_back({ sharky, sharkx, s, d, z });
	}

	for (fisherLocation; fisherLocation <= c; fisherLocation++)
	{
		catchFish(fisherLocation);
		sharkMove();
		sharkEat();
		for (int i = 1; i <= r; i++)
		{
			for (int j = 1; j <= c; j++)
			{
				if (map[i][j].size() >= 1)
				{
					sharks.push_back({ i,j,map[i][j][0].speed,map[i][j][0].direction,map[i][j][0].size });
				}
			}
		}
	}

	cout << fishSum;

	return 0;
}