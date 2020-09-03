#include<iostream>

using namespace std;

long long arr[101] = { 0 };

long long dp(int n)
{
	if (arr[n] != 0)
		return arr[n];

	arr[n] = dp(n-1) + dp(n-5);
	return arr[n];
}
int main()
{
	int t, n;
	cin >> t;

	arr[1] = 1;
	arr[2] = 1;
	arr[3] = 1;
	arr[4] = 2;
	arr[5] = 2;
	arr[6] = 3;
	arr[7] = 4;
	arr[8] = 5;
	arr[9] = 7;
	arr[10] = 9;

	for (int i = 0; i < t; i++)
	{
		cin >> n;
		cout << dp(n) << "\n";
	}


}