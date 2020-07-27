#include<iostream>

using namespace std;

int main()
{
	int a, b, v;
	int now = 0;
	int day = 0;

	cin >> a >> b >> v;

	if (v % (a - b) + (a - b) == a)
		cout << v / (a - b);

	else if (v % (a - b) != 0)
		cout << v / (a - b) + 1;

	else
		cout << v / (a - b) - 1;

	return 0;
}

/*
1. 달팽이가 낮에 다 오른 경우
-범위치를 넘겼을 때
5 2 16
v%(a-b) != 0
cout << v/(a-b)+1;

- 범위치를 딱 채웠을 때
5 2 17

v%(a-b) + (a-b) == a 인경우네 나머지 + 뺀 값
cout << v/(a-b);


2. 달팽이가 낮에 다 오르지 못한 경우

cout << v / (a-b) + 1;

3 1 23

12일째 다 오름
*/
