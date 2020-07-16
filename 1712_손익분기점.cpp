#include<iostream>

using namespace std;

int main()
{
	int a, b, c;

	cin >> a >> b >> c;

	int makeCost = c-b;
	int fixed = a;

	if (makeCost <= 0)
		cout << -1;
	else
		cout << fixed / makeCost + 1;


	return 0;

}