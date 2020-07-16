#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<char> word;
	char tmp;

	while ((tmp = cin.get()) != '\n')
	{
		word.push_back(tmp);
	}

	int cnt = 0;
	for (int i = 0; i < word.size(); i++)
	{
		if (word[i] == 'c' && i+1 < word.size())
		{
			if(word[i+1] == '=' || word[i+1] == '-')
				i++;
		}
		else if (word[i] == 'd' && i + 1 < word.size())
		{
			if (word[i + 1] == 'z' && i + 2 < word.size())
			{
				if (word[i + 2] == '=')
					i += 2;
			}
			else if (word[i + 1] == '-')
				i++;
		}
		else if (word[i] == 'l' && i + 1 < word.size())
		{
			if (word[i + 1] == 'j')
				i++;
		}
		else if (word[i] == 'n' && i + 1 < word.size())
		{
			if (word[i + 1] == 'j')
				i++;
		}
		else if (word[i] == 's' && i + 1 < word.size())
		{
			if (word[i + 1] == '=')
				i++;
		}
		else if (word[i] == 'z' && i + 1 < word.size())
		{
			if (word[i + 1] == '=')
				i++;
		}
		cnt++;
	}

	cout << cnt;


	return 0;

}