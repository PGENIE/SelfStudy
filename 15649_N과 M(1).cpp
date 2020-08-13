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

			visited[i] = 1;
			cnt++;

			result[cnt] = i;

			dfs(cnt);

			cnt--;
			visited[i] = 0;
	}
}

int main()
{
	cin >> n >> m;

	dfs(0);

	return 0;

}

/*
20200812 string으로 추가해서 sorting 해보기
int main()
{
	cin >> n >> m;

	vector<int> coord(n, 0);
	vector<int> result;
	vector<string> v1;

	for (int i = 0; i < m; i++)
	{
		coord[n - i - 1] = 1;
	}

	do {
		string tmp = "";
		for (int i = 0; i < n; i++)
		{
			if (coord[i] == 1)
			{
				tmp += to_string(i + 1) + " ";
			}
		}
		v1.push_back(tmp);

	} while (next_permutation(coord.begin(), coord.end()));


	sort(v1.begin(), v1.end());

	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << "\n";
	}



	return 0;
}
*/