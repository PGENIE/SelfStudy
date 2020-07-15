#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
	int a, b;
	
	cin >> a >> b;


	int a_units = a%10;
	a /= 10;
	int a_tens = a%10;
	a /= 10;
	int a_hundreds=a%10;

	a = (a_units * 100) + (a_tens * 10) + (a_hundreds);

	int b_units = b % 10;
	b /= 10;
	int b_tens = b % 10;
	b /= 10;
	int b_hundreds = b % 10;

	b = (b_units * 100) + (b_tens * 10) + (b_hundreds);

	if (a < b)
		cout << b;
	else
		cout << a;


}