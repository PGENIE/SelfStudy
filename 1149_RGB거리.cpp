#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int n;
int map[1001][3];


int main()
{
	int n;
	int a;

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> a;
			map[i][j] = a;
		}
	}

	int cnt = 1;
	int color = 0;
	int nextColor;
	vector<int> minColor;
	for (int i = 0; i < 3; i++)
	{
		cout << "\n\n";
		int min = 0;
		color = i;
		cnt = 1;
		while (1)
		{
			min += map[cnt][color];
			cout << map[cnt][color] << "\n";

			if (cnt == n) //n번째까지 다더했네~
				break;

			switch (color)
			{
			case 0:
				map[cnt + 1][1] < map[cnt + 1][2] ? nextColor = 1 : nextColor = 2;
				break;
			case 1:
				map[cnt + 1][0] < map[cnt + 1][2] ? nextColor = 0 : nextColor = 2;
				break;
			case 2:
				map[cnt + 1][0] < map[cnt + 1][1] ? nextColor = 0 : nextColor = 1;
				break;
			}
			color = nextColor;
			cnt++;
		}
		cout << "min? " << min<<"\n";
		minColor.push_back(min);
		
	}

	sort(minColor.begin(), minColor.end());

	cout << minColor[0];
	
	return 0;

}