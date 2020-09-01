#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

vector<int> arr;

int main()
{
	int t;

	cin >> t;

	//1. 아리스토테네스의 체로 10000까지 거르기 // 소수이면 true.아니면 false

	arr.push_back(2);

	for (int i =  3; i <= 10000; i++)
	{
		bool check = false; 
		for (int j = 2; j <= sqrt(i); j++)
		{
			if (i % j == 0)
			{
				check = true; //하나라도 나눠지면 소수아님
				break;
			}
		}
		if (check == false)
			arr.push_back(i);
	}

	//2. 테스트케이스만큼 돌리기
	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;
		
		int nowUp = 0;
		int nowDown = 0;
		bool sameExist = false;
		for (int j = 0; j < arr.size(); j++)
		{
			if (arr[j] > n / 2)
			{
				nowUp = j;
				nowDown = j-1;
				break;
			}
				

			if (arr[j] == n / 2)
			{
				cout << n / 2 << " " << n / 2 << "\n";
				sameExist = true;
				break;
			}

		}
		if (sameExist == true)
			continue;

		while (1)
		{
			if (arr[nowUp] + arr[nowDown] == n)

			{
				cout << arr[nowDown] << " " << arr[nowUp] << "\n";
				break;
			}

			if (arr[nowUp] + arr[nowDown] < n)
			{
				nowUp += 1;
			}

			else
				nowDown -= 1;

		}


	}
}
