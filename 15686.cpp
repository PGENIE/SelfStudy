#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#pragma warning(disable:4996)

using namespace std;

typedef struct pos {
	int y;
	int x;
}pos;
vector<vector<int>> map;
vector<pos> house;
vector<pos> chicken;
vector<pos> chosen;
int result = 2e9;
int min = 9999;



void findMin()
{
	int i, j;
	int min = 2e9;
	int sum = 0;

	for (i = 0; i < house.size(); i++)
	{
		for (j = 0; j < chosen.size(); j++)
		{
			if (min > abs(house[i].y - chosen[j].y) + abs(house[i].x - chosen[j].x))
				min = abs(house[i].y - chosen[j].y) + abs(house[i].x - chosen[j].x);
		}
		sum += min;
		min = 2e9;
	}

	if (result > sum)
		result = sum;
}

void chooseChicken(int cnt)
{
	int i, j;

	vector<int> coord(chicken.size(), 0);
	for (i = 0; i < cnt; i++)
	{
		coord[chicken.size()-1-i] = 1;
	}

	do 
	{
		for (i = 0; i < chicken.size(); i++)
		{
			if (coord[i] == 1)
			{
				chosen.push_back(chicken[i]);
			}
		}
		findMin();
		chosen.clear();
	} while (next_permutation(coord.begin(), coord.end()));

}


int main()
{
	int n, m;

	scanf("%d %d", &n, &m);

	map.resize(n, vector<int>(n, 0));

	int i,j;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%d", &map[i][j]);
			
			//한 집당 모든 치킨 집 거리를 비교해서 최솟값들만 더하면 도시의 치킨거리.
			
			pos tmp;
			if (map[i][j] == 1)
			{
				tmp.y = i; tmp.x = j;
				house.push_back(tmp);
			}
			else if (map[i][j] == 2)
			{
				tmp.y = i; tmp.x = j;
				chicken.push_back(tmp);
			}
		}
	}

	for (i = 1; i <= m; i++)
	{
		chooseChicken(i);
	}

	printf("%d", result);

	system("pause");
}