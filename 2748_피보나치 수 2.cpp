#include<iostream>
#include<vector>

using namespace std;

vector<long long> fibo;


//�Ǻ���ġ �� 80���ʹ� �׳� int�� ������ �ȵǳ�..
//Ʋ�ȴٰ� �� ���� �Է°��� �ּ�, �ִ� �����غ���.
int main()
{

	fibo.push_back(0);
	fibo.push_back(1);

	int n;

	cin >> n;

	for (int i = 2; i <= n; i++) //i����
	{
		long long tmp = fibo[i - 2];
		long long tmp2 = fibo[i - 1];

		fibo.push_back(tmp + tmp2);
	}

	cout << fibo[n];

	return 0;

}

