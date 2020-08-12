#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, m;


// dfs Ȱ���ؼ� Ǯ� ���� - �� ������� route�� ���ؼ� 1-2-3 �� 3-2-1�� ���Բ� �����ؼ� Ȯ���ߴ�. ������ 4C2�϶� 1 2 / 1 3 / 1 4 /�̰� ������ Ȯ���� �� 2 / 1�� �ȳ�����-> ���? 2���� ū ���� Ȯ���ϰԲ�! �ؼ� ¥������
vector<int> visited;
vector<int> result;

vector<int> tmp;
vector<int> route;


void dfs(int cnt)
{
	if (cnt == m)
	{

		int sum = 0;
		vector<int> tmpsort = tmp;
		sort(tmpsort.begin(), tmpsort.end());

		for (int i = 0; i <= tmpsort.size() - 1; i++)
		{
			sum += tmpsort[i] * (pow(10, tmpsort.size() - 1 - i));
		}

		for (int i = 0; i < route.size(); i++)
		{
			if (route[i] == sum)
				return;
		}
		route.push_back(sum);


		for (int i = 0; i < m; i++)
		{
			cout << result[i] << " ";
		}
		cout << "\n";

		return;
	}

	for (int i = 1; i <= n; i++)
	{
		if (visited[i] == 0)
		{
			visited[i] = 1;
			result[cnt] = i;

			tmp.push_back(i);

			dfs(cnt + 1);

			visited[i] = 0;
			tmp.erase(tmp.begin() + tmp.size() - 1);
		}
	}
}

int main()
{
	cin >> n >> m;

	visited.resize(n + 1, 0);
	result.resize(m, 0);

	dfs(0);

	return 0;
}

/*
next_permutation �̿��ؼ� Ǯ� ����

int main()
{
	cin >> n >> m;

	vector<int> coord(n, 0);
	vector<int> result;

	for (int i = 0; i < m; i++)
	{
		coord[n - i - 1] = 1;
	}

	do {

		for (int i = 0; i < n; i++)
		{
			if (coord[i] == 1)
			{
				result.push_back(i + 1);
			}
		}

	} while (next_permutation(coord.begin(), coord.end()));

	for (int i = result.size() - m; i >= 0; i -= m)
	{
		for (int j = 0; j < m; j++)
		{
			cout << result[i + j] << " ";
		}
		cout << "\n";
	}
	return 0;
}
*/