#include<iostream>
#include<vector>

using namespace std;

int zero = 0;
int one = 0;

vector<int> arr;

//시간초과
int fibo(int n)
{
	if (n == 0)
	{
		zero++;
		return 0;
	}

	if (n == 1)
	{
		one++;
		return 1;
	}

	return fibo(n-1) + fibo(n-2);
}
int main()
{
	int testCase;
	
	cin >> testCase;

	for (int i = 0; i < testCase; i++)
	{
		int num;
		cin >> num;

		fibo(num);

		cout << zero << " " << one << "\n";

		zero = 0;
		one = 0;
	}
}