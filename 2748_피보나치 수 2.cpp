#include<iostream>
#include<vector>

using namespace std;

vector<long long> fibo;


//피보나치 수 80부터는 그냥 int로 감당이 안되네..
//틀렸다고 뜰 때는 입력값의 최소, 최대 대입해보기.
int main()
{

	fibo.push_back(0);
	fibo.push_back(1);

	int n;

	cin >> n;

	for (int i = 2; i <= n; i++) //i번쨰
	{
		long long tmp = fibo[i - 2];
		long long tmp2 = fibo[i - 1];

		fibo.push_back(tmp + tmp2);
	}

	cout << fibo[n];

	return 0;

}

