#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{

	char word[100];
	char tmp;
	char alphabet = 'a';

	int a = 0;
	while ((tmp = cin.get())!='\n')
	{
		word[a] = tmp;
		a++;		
	}

	for (int i = 0; i < 26; i++)
	{
		alphabet = 'a'+i;
		bool exist = false;

		for (int j = 0; j < a; j++)
		{
			if (alphabet == word[j])
			{
				cout << j << " ";
				exist = true;
				break;
			}
		}
		if (exist == false)
			cout << -1 << " ";
	}


	/*
	while (cin >> tmp)
	{
		bool exist = false;
		for (int i = 0; i < 26; i++)
		{
			char alphabet = 'a'; //a´Â97¹ø
			alphabet += i;

			if (tmp == alphabet)
			{
				cout << i << " ";
				exist = true;
				break;
			}
		}
		if (exist == false)
		{
			cout << -1 << " ";
		}

	}
	*/

}