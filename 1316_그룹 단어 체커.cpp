#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int n;
	vector<char> word;
	char tmp=' ';
	int result = 0;

	cin >> n;
	tmp = cin.get(); //°³Çà

	for (int i = 0; i < n; i++)
	{
		bool consecutive = true;
		tmp = cin.get();
		word.push_back(tmp);

		for (int j = 1; j < 100; j++)
		{
			if (consecutive == false)
			{
				while (1)
				{
					if ((tmp = cin.get()) == '\n')
						break;
				}
				break;
			}
			tmp = cin.get();
			if (tmp == '\n')
				break;

			if (tmp != word[word.size()-1])
			{				
				for (int k = 0; k < word.size(); k++)
				{
					if (tmp == word[k])
					{
						consecutive = false;
						break;
					}
				}
				if (consecutive == true)
					word.push_back(tmp);
			}
		}
		if (consecutive == true)
			result++;
		else
			consecutive = true;

		word.clear();
	}

	cout << result;

	return 0;

}