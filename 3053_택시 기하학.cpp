#define _USE_MATH_DEFINES
#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	double r;
	cin >> r;

	double a, b;
	a = M_PI * r * r;
	b = 2 * r * r;

	printf("%lf\n", a);
	printf("%lf\n", b);

	return 0;
}
