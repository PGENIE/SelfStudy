#include<iostream>

using namespace std;

int factorial(int a);

int main()
{
	int a;
	cin >> a;

	cout << factorial(a);

	return 0;
}

int factorial(int a)
{
	if (a == 0)
	{
		return 1;
	}
	if (a == 1)
	{
		return 1;
	}

	return factorial(a - 1)* a;

}