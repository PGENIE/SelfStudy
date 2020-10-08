#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#define WHITE 0
#define GRAY 1
#define BLACK 2

using namespace std;

int n, m, v;
vector<vector<int>> map;
stack<int> s;
queue<int> q;
int color1[1001] = { 0 };
int color2[1001] = { 0 };

void dfs(int v)
{
	s.push(v);
	cout << v << " ";
	color1[v] = BLACK;

	for (int i = 1; i < n + 1; i++)
	{
		if (map[v][i] == 1 && color1[i] == WHITE)
		{
			dfs(i);
		}
	}
	s.pop();
}

void bfs(int v)
{
	q.push(v);
	color2[v] = GRAY;

	int now = q.front();
	cout << now << " ";
	q.pop();
	color2[v] = BLACK;
	int black = 1;


	while (1)
	{
		if (black == n)
			break;

		for (int i = 1; i < n + 1; i++)
		{
			if (map[now][i] == 1 && color2[i] == WHITE)
			{
				q.push(i);
				color2[i] = GRAY;
			}
		}
		if (q.size() == 0)
			break;
		now = q.front();
		cout << now << " ";
		q.pop();
		color2[now] = BLACK;
		black++;

	}

}


int main()
{
	cin >> n >> m >> v;

	map.resize(n + 1, vector<int>(n + 1, 0));

	int x, y;

	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		map[x][y] = 1;
		map[y][x] = 1;
	}

	dfs(v);
	cout << "\n";
	bfs(v);

}