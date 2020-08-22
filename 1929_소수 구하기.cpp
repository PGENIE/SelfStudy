#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int start, end;

	cin >> start >> end;

	vector<bool> arr(end+1, true);

	if (end > 2)
		arr[2] = true;

	for (int i = 2; i < end; i++)
	{
		for (int j = 2; j*i <= end; j++)
		{
			arr[i * j] = false;
		}
	}

	for (int i = start; i < arr.size(); i++)
	{
		if (arr[i] == true && i!= 1)
			cout << i << "\n";
	}

	return 0;
}

