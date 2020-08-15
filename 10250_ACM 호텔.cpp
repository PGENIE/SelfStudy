#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> hotel;

int h, w, n;

void findRoom()
{
	int order;
	int height;

	if (n % h == 0)
		order = n / h;
	else
		order = (n / h) + 1;


	if (n % h == 0)
		height = h;
	else
		height = n % h;



	cout << height;
	if (order < 10)
		cout << "0" << order;
	else
		cout << order;

	cout << "\n";

	return;
}
int main()
{
	//h * w 사이즈 호텔, n번째손님
	int testCase;

	cin >> testCase;

	for (int i = 0; i < testCase; i++)
	{
		cin >> h >> w >> n;
		hotel.resize(h, vector<int>(w));
		findRoom();
	}
}

/*
2
6 12 10
30 50 72
*/