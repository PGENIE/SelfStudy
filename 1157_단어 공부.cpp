#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
	//a 는 97부터, A는 65부터
	
	char word[1000000];
	int alphabet[26] = { 0 };
	char tmp;
	
	while (1)
	{
		if ((tmp = cin.get())=='\n')
			break;

		if (97 <= tmp)
		{
			alphabet[tmp - 97]++;
		}
		else
		{
			alphabet[tmp + 32 - 97]++;
		}
	}

	//alphabet 정렬
	int max = 0;
	int maxcnt = 0;
	int location;

	for (int i = 0; i < 26; i++)
	{
		if (alphabet[i] >= max)
		{
			if (alphabet[i] > max)
			{
				maxcnt = 0;
				max = alphabet[i];
				maxcnt++;
				location = i;
			}
			else
			{
				maxcnt++;
			}
		}

	}

	if (maxcnt > 1)
	{
		cout << '?';
	}
	else
	{
		char result = 'A'+location;
		cout << result;
	}

}