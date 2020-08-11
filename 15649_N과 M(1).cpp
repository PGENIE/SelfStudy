#include<iostream>

using namespace std;

int n, m;
int visited[9] = { 0 };
int result[8];


void dfs(int cnt)
{
	int i, j;

	if (cnt == m)
	{
		//종료조건
		for (i = 1; i <= m; i++)
		{
			cout << result[i] << " ";
;		}
		cout << "\n";
		return;
	}

	for(i = 1; i <= n; i++)
	{
		if (visited[i] == 0)
		{
			visited[i] = 1;
			cnt++;

			result[cnt] = i;

			dfs(cnt);

			cnt--;
			visited[i] = 0;
		}
	}
}

int main()
{
	cin >> n >> m;

	dfs(0);

	return 0;
}