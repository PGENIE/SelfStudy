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

	
	//find ������ ���� for�� ������ ��, �� ���� now�� ���;��ϴµ�...
	for (int i = -1; i < 2; i++)
	{ 
		int tmpdist = dist;
		tmpdist += i;
		if (tmpdist != 0) //0��ŭ�ǰŸ� �ǹ̾���
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

		now = 1; //����ġ
		dist = 1; //�����̵��Ÿ�
		
		last = arrival - 1; //������ ��ġ ����

		cnt = 2; //ù �̵��� �������̵��� �̹� ī��Ʈ

		find(cnt);

		sort(result.begin(), result.end());
		cout << result[0];
		result.clear();
	}
	



	return 0;
}

