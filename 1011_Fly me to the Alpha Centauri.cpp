#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int departure, arrival;
int now, dist, last, cnt;
vector<int> result;

void find(int cnt)
{
	if (last - now == 0)
	{
		result.push_back(cnt);
		return;
	}

	if (now > last)
		return;

	
	//find 나오고 다음 for문 돌았을 때, 이 때의 now가 나와야하는데...
	for (int i = -1; i < 2; i++)
	{ 
		int tmpdist = dist;
		tmpdist += i;
		if (tmpdist != 0) //0만큼의거리 의미없음
		{
			dist = tmpdist;
			now += dist;
			find(cnt + 1);
			now -= dist;

		}
	}
	
}
int main()
{
	int testCase;
	int i, j;

	cin >> testCase;
	
	
	for (i = 0; i < testCase; i++)
	{
		cin >> departure >> arrival;

		now = 1; //현위치
		dist = 1; //직전이동거리
		
		last = arrival - 1; //마지막 위치 직전

		cnt = 2; //첫 이동과 마지막이동은 이미 카운트

		find(cnt);

		sort(result.begin(), result.end());
		cout << result[0];
		result.clear();
	}
	



	return 0;
}

