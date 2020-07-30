#include<iostream>
#include<vector>
#include<algorithm>
#include<String>


using namespace std;

vector<vector<int>> board;

int check(int y, int x)
{
	//°ËÈòÀ¸·Î Ä¥ÇÏ´Â °æ¿ì °¹¼ö vs Èò°ËÀ¸·Î Ä¥ÇÏ´Â °æ¿ì °¹¼ö ºñ±³
	int c = 0;
	int cnt = 0;
	int before = board[y][x];
	vector<int> check1 = { 1,0,1,0,1,0,1,0 };
	vector<int> check2 = { 0,1,0,1,0,1,0,1 };

	//°ËÈò
	for (int i = 0; i < 8; i++)
	{
		c = 0;
		for (int j = 0; j < 8; j++)
		{
			if (i == 0 || i % 2 == 0)
			{
				if (board[y + i][x + j] != check1[c])
					cnt++;
			}
			else
			{
				if (board[y + i][x + j] != check2[c])
					cnt++;
			}
			c++;
		}
	}

	int cnt2=0;
	// Èò°Ë
	for (int i = 0; i < 8; i++)
	{
		c = 0;
		for (int j = 0; j < 8; j++)
		{
			if (i == 0 || i % 2 == 0)
			{
				if (board[y + i][x + j] != check2[c])
					cnt2++;
			}
			else
			{
				if (board[y + i][x + j] != check1[c])
					cnt2++;
			}
			c++;
		}
	}

	return cnt<cnt2? cnt:cnt2;
}

int main()
{
	int n, m;
	char tmp;

	cin >> n >> m;

	board.resize(n, vector<int>(m, 0));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> tmp;
			if (tmp == 'B')
				board[i][j] = 1;
			else if (tmp == 'W')
				board[i][j] = 0;
		}
	}

	int y = 0; int x = 0;

	vector<int> result;
	for (int i = 0; i <= n - 8; i++)
	{
		for (int j = 0; j <= m - 8; j++)
		{
			result.push_back(check(i, j));
		}
	}

	sort(result.begin(), result.end());

	cout << result[0];
}
