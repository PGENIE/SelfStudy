#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

int main()
{
	vector<int> weight;
	vector<int> height;
	vector<int> answer;

	int n, w, h;

	cin >> n;

	answer.resize(n, 0);

	for (int i = 0; i < n; i++)
	{
		cin >> w >> h;
		weight.push_back(w);
		height.push_back(h);
	}
	
	//나보다 덩치 큰 사람 수 세가지고 하면 대네

	for (int i = 0; i < n; i++)
	{
		int cnt = 0;
		for (int j = 0; j < n; j++)
		{
			if (weight[i] < weight[j] && height[i] < height[j])
				cnt++;

			else if (weight[i] == weight[j] && height[i] < height[j])
				cnt++;

			else if (weight[i] < weight[j] && height[i] == height[j])
				cnt++;
		}
		cout << cnt + 1 << " ";
	}

	


	return 0;
}
