#include<iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		char tmp;
		cin >> tmp;
		sum += tmp - 48;
	}

	cout << sum;

}