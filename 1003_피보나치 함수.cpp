#include<iostream>
#include<vector>

using namespace std;

typedef struct call {
	int callZero;
	int callOne;
}call;

vector<call> fibo;

int main()
{
	int t;
	int n;
	
	cin >> t;

	fibo.push_back({ 1,0 });
	fibo.push_back({ 0,1 });

	for (int i = 0; i < t; i++)
	{
		cin >> n;

		if (fibo.size() - 1 >= n)
		{
			cout << fibo[n].callZero << " " << fibo[n].callOne << "\n";
		}
		else
		{
			int now = fibo.size() - 1;
			while (1)
			{
				int callZeroSum = fibo[now - 1].callZero + fibo[now].callZero;
				int callOneSum = fibo[now - 1].callOne + fibo[now].callOne;

				fibo.push_back({ callZeroSum,callOneSum });
				
				now += 1;

				if (now == n)
				{
					cout << fibo[n].callZero << " " << fibo[n].callOne << "\n";
					break;
				}
			}
			

		}

	}
}
