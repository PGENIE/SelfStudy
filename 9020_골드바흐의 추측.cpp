#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

vector<int> arr;

int main()
{
	int t;

	cin >> t;

	//1. �Ƹ������׳׽��� ü�� 10000���� �Ÿ��� // �Ҽ��̸� true.�ƴϸ� false

	arr.push_back(2);

	for (int i =  3; i <= 10000; i++)
	{
		bool check = false; 
		for (int j = 2; j <= sqrt(i); j++)
		{
			if (i % j == 0)
			{
				check = true; //�ϳ��� �������� �Ҽ��ƴ�
				break;
			}
		}
		if (check == false)
			arr.push_back(i);
	}

	//2. �׽�Ʈ���̽���ŭ ������
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
