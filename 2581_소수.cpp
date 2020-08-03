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

	if (m == 1) //1은 소수가 아니니까 빼주고 시작하기
	{
		m++;
	}

	for (int i = m; i <= n; i++) //m부터 n까지 확인
	{
		bool isPrime = true;
		for (int j = 2; j <= sqrt(i); j++) //i가 소수인가?를 확인하는것
		{
			if (i % j == 0)//하나라도 딱떨어지면 소수가 아님
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

