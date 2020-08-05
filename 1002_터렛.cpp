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

		if (x1 == x2 && y1 == y2 && r1 == r2) //���� ��ġ
			cout << -1 << "\n";
		else if (x1 == x2 && y1 == y2 && r1 != r2) //��ǥ�� ��ġ�ϳ� �Ÿ��� �ٸ�
			cout << 0 << "\n";
		else if (pow(r1 + r2, 2) == powDistance) //����
			cout << 1 << "\n";
		else if (pow(r1 - r2, 2) == powDistance) //����
			cout << 1 << "\n";
		else if (pow(r1 - r2, 2) > powDistance) //�� ���� �ٸ� �� ����. �ȸ���.
			cout << 0 << "\n";
		else if (pow(r1 + r2, 2) > powDistance) //�� ������ ����
			cout << 2 << "\n";
		else //�Ÿ� �ƿ� �ٱ�
			cout << 0 << "\n";
	}
	return 0;
	

}

