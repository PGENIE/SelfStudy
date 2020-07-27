#include<iostream>

using namespace std;

int main()
{
	int a, b, v;

	cin >> a >> b >> v;

	//마지막날은 내려가지 않으므로
	int day = (v - b) / (a - b);

	if ((v - b) % (a - b) != 0)
		cout << day + 1;
	else
		cout << day;

	return 0;
}

