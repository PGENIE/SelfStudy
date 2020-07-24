#include<iostream>

using namespace std;

int Fibo(int a);

int main()
{
	int a;
	cin >> a;

	cout << Fibo(a);
}

int Fibo(int a)
{
	if (a == 0)
		return 0;
	if (a == 1)
		return 1;

	return Fibo(a - 1) + Fibo(a - 2);
}
