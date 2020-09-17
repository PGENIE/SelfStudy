#include<iostream>
#include<math.h>

using namespace std;

int main()
{
	int testCase;
	int departure, arrival;
	int i, j;
	int distance;

	cin >> testCase;

	for (i = 0; i < testCase; i++)
	{
		cin >> departure;
		cin >> arrival;
		distance = arrival - departure;

		//가장 가까운, 작은 제곱수를 찾는다.
		int find = 0;

		while (1)
		{
			if (distance - pow(find, 2) < 0)
			{
				find--;
				break;
			}
			if (distance - pow(find, 2) == 0)
			{
				break;
			}
			find++;
		}
		//find가 가장 가까운 작은 제곱수.
		
		int findnow = 2 * find - 1; //find까지 왔을 때 최소 수
		int powfind = pow(find, 2);
		if (powfind == distance)
		{
			cout << findnow << "\n";
			continue;
		}

		if ((distance - powfind) % find == 0)
			cout << findnow + ((distance - powfind) / find) << "\n";
		else
			cout << findnow + ((distance - powfind) / find) +1<< "\n";

	}

	return 0;
}