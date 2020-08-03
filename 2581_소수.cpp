#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

int main()
{
	int m, n;
	vector<int> prime;
	cin >> m;
	cin >> n;

	if (m == 1) //1�� �Ҽ��� �ƴϴϱ� ���ְ� �����ϱ�
	{
		m++;
	}

	for (int i = m; i <= n; i++) //m���� n���� Ȯ��
	{
		bool isPrime = true;
		for (int j = 2; j <= sqrt(i); j++) //i�� �Ҽ��ΰ�?�� Ȯ���ϴ°�
		{
			if (i % j == 0)//�ϳ��� ���������� �Ҽ��� �ƴ�
			{
				isPrime = false;
				break;
			}
		}
		
		if (isPrime == true)
		{
			prime.push_back(i);
		}
	}

	if (prime.size() == 0)
	{
		cout << -1;
		return 0;
	}

	int result = 0;
	for (int i = 0; i < prime.size(); i++)
	{
		result += prime[i];
	}
	cout << result << "\n" << prime[0];

	return 0;
	

}

