#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

int main()
{
	int n;
	int x1, x2, y1, y2;
	int r1, r2;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> x1 >> y1 >> r1;
		cin >> x2 >> y2 >> r2;
		
		int powDistance = pow((x1 - x2), 2) + pow((y1 - y2), 2);

		if (x1 == x2 && y1 == y2 && r1 == r2) //원이 일치
			cout << -1 << "\n";
		else if (x1 == x2 && y1 == y2 && r1 != r2) //좌표는 일치하나 거리가 다름
			cout << 0 << "\n";
		else if (pow(r1 + r2, 2) == powDistance) //외접
			cout << 1 << "\n";
		else if (pow(r1 - r2, 2) == powDistance) //내접
			cout << 1 << "\n";
		else if (pow(r1 - r2, 2) > powDistance) //한 원이 다른 원 포함. 안만남.
			cout << 0 << "\n";
		else if (pow(r1 + r2, 2) > powDistance) //두 점에서 만남
			cout << 2 << "\n";
		else //거리 아예 바깥
			cout << 0 << "\n";
	}
	return 0;
	

}

