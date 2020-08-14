#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> num;
vector<int> oprt(4);
int main()
{
	int numCnt;
	int i, j;

	cin >> numCnt;
	num.resize(numCnt);

	for (i = 0; i < numCnt; i++)
	{
		int tmp;
		cin >> tmp;
		num[i] = tmp;
	}

	for (i = 0; i < 4; i++)
	{
		int tmp2;
		cin >> tmp2;
		oprt[i] = tmp2;
	}

	//          + - * / ÀÇ °¹¼ö. °¹¼ö¸¸Å­ 
	// n-1°³ÀÇ operator ¹è¿­À» ¸¸µé¸é µÊ.
	vector<int> oprtCoord;

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < oprt[i]; j++)
		{
			oprtCoord.push_back(i);
		}
	}

	vector<int> resultArr;
	do {

		int result = num[0];

		for (i = 0; i < numCnt - 1; i++)
		{
			if (oprtCoord[i] == 0)
				result += num[i + 1];

			else if (oprtCoord[i] == 1)
				result -= num[i + 1];
			
			else if (oprtCoord[i] == 2)
				result *= num[i + 1];

			else if (oprtCoord[i] == 3)
				result /= num[i + 1];
				
		}

		resultArr.push_back(result);


	} while (next_permutation(oprtCoord.begin(), oprtCoord.end()));

	sort(resultArr.begin(), resultArr.end());

	cout << resultArr[resultArr.size() - 1] << "\n" << resultArr[0];

	return 0;
}