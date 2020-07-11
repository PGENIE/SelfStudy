#include<stdio.h>
#include<vector>
#pragma warning (disable:4996)

using namespace std;

typedef struct pos {
	int y;
	int x;
}pos;

int r, c, t;
vector<vector<int>> map;
vector<vector<int>> newMap;
vector<pos> machine;



void diffuseDirt()
{
	int i, j;

	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			if (map[i][j] > 0)
			{
				//기존 맵에서는 확장이 됐다고 가정하고 남은 양을 자리에 두고
				//확산된 양은 새 맵에 뿌린다.
				//그리고 합친다.
				vector<int> direction(4, 1);

				// 동 서 남 북 나가질때
				if (j == c - 1)
				{
					direction[0]--;
				}
				if (j == 0)
				{
					direction[1]--;
				}
				if (i == r - 1)
				{
					direction[2]--;
				}
				if (i == 0)
				{
					direction[3]--;
				}

				//동서남북에 공기청정기 있을 때
				if (j != c - 1 && j != 0 && i != r - 1 && i != 0)
				{
					if (map[i][j + 1] == -1)
					{
						direction[0]--;
					}
					if (map[i][j - 1] == -1)
					{
						direction[1]--;
					}
					if (map[i + 1][j] == -1)
					{
						direction[2]--;
					}
					if (map[i - 1][j] == -1)
					{
						direction[3]--;
					}
				}
				
				int availDirection = 0;
				availDirection = direction[0] + direction[1] + direction[2] + direction[3];

				int diffuse = map[i][j] / 5;
				map[i][j] -= availDirection * (map[i][j] / 5);

				for (int k = 0; k < 4; k++)
				{
					if (k == 0 && direction[k] == 1)
					{
						newMap[i][j + 1] += diffuse;
					}
					if (k == 1 && direction[k] == 1)
					{
						newMap[i][j - 1] += diffuse;
					}
					if (k == 2 && direction[k] == 1)
					{
						newMap[i+1][j] += diffuse;
					}
					if (k == 3 && direction[k] == 1)
					{
						newMap[i-1][j] += diffuse;
					}
				}
				printf("\n[%d,%d]확인후\n", i, j);
				printf("map\n");
				for (int a = 0; a < r; a++)
				{
					for (int b = 0; b < c; b++)
					{
						printf("%d ", map[a][b]);
					}
					printf("\n");
				}

				printf("\nnewMap\n");
				for (int a = 0; a < r; a++)
				{
					for (int b = 0; b < c; b++)
					{
						printf("%d ", newMap[a][b]);
					}
					printf("\n");
				}

			}
		}
	}
}

void dirtSum()
{
	int i, j;

	for (int i = 0; i < r; i ++)
	{
		for (int j = 0; j < c; j++)
		{
			map[i][j] += newMap[i][j];
		}
	}

	newMap.clear();
	newMap.resize(r, vector<int>(c, 0));
}


void machineOn()
{

}

int main()
{
	scanf("%d %d %d", &r, &c, &t);
	
	map.resize(r, vector<int>(c, 0));
	newMap.resize(r, vector<int>(c, 0));

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			scanf("%d", &map[i][j]);

			if (map[i][j] == -1)
			{
				pos tmp;
				tmp.y = i; tmp.x = j;
				machine.push_back(tmp);
			} //top, bottom 순으로 들어갈 것
			
		}
	}
	int i, j;

	diffuseDirt();
	printf("map\n");
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}

	printf("\n\nnewmap\n");
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}

	dirtSum();
	printf("dirtSum\n");
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}

	system("pause");

	machineOn();
}