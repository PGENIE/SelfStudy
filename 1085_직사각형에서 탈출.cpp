#include<iostream>
#include<vector>

using namespace std;


int main()
{
	int x, y, w, h;

	cin >> x >> y >> w >> h;

	//�Ʒ����� �Ÿ�
	int bottom = y;
	//��
	int top = h - y;
	//����
	int left = x;
	//������
	int right = w - x;

	int min;

	if (bottom < top)
		min = bottom;
	else
		min = top;

	if (left < right)
	{
		if (min == bottom)
		{
			if (left < bottom)
				min = left;
		}
		if (min == top)
		{
			if (left < top)
				min = left;
		}
	}

	if (right < left)
	{
		if (min == bottom)
		{
			if (right < bottom)
				min = right;
		}
		if (min == top)
		{
			if (right < top)
				min = right;
		}
	}

	cout << min;


	return 0;
}
