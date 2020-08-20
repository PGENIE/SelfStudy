#include<iostream>
#include<vector>

using namespace std;

int departure, arrival;
int now;
int cnt = 0; 

int result = 2100000000;

void dfs(int now, int lastDistance)
{
	if (now == arrival && lastDistance == 1)//��������
	{
		if (cnt < result)
			result = cnt;
		return;
	}
	if (now > arrival)
		return;

	for (int i = -1; i < 2; i++)
	{
		if (lastDistance + i <= 0) //0�����̸� �����̴� �ǹ̰� �����Ƿ�
			continue;

		cnt++; //�����δ�.
		dfs(now + lastDistance + i, lastDistance+i);
		cnt--;
	}

}
int main()
{
	int testCase;
	cin >> testCase;


	for (int i = 0; i < testCase; i++)
	{
		cin >> departure >> arrival;

		now = departure;
		int lastDistance = 0;

		dfs(now, lastDistance);
		
		cout << result << "\n";
		result = 2100000000;
	}

	return 0;
}

