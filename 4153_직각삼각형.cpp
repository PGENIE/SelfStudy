#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

int main()
{
	int a, b, c;
	vector<int> triangle;

	while (1)
	{
		cin >> a >> b >> c;
		
		if (a == 0 && b == 0 && c == 0)
			break;

		triangle.push_back(a);
		triangle.push_back(b);
		triangle.push_back(c);

		sort(triangle.begin(), triangle.end());

		if (pow(triangle[0], 2) + pow(triangle[1], 2) == pow(triangle[2], 2))
		{
			cout << "right";
		}
		else
		{
			cout << "wrong";
		}

		cout << "\n";
		
		triangle.clear();
	}
	return 0;
	

}

