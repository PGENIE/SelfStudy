#include<iostream>
#include<vector>

using namespace std;
//���� : ����, ����, ����
vector<int> arr;


void selectionSort(int n)
{
	//���� ����. �ڸ� �����ź��� �����ؼ� �� �ڸ��� �´� �ָ� ã�ƿ´�. O(n^2)
	/*
	9 5 3 7 1
	(1) 0��° �ڸ��� ���� ���� �ִ�? => ���� ��ȸ�ؼ� min�� 1 ã��.
	(2) 1��° �ڸ��� ���� ���� �ִ�? => 0��° �� �����ϰ� 1~n-1��° ��ȸ�ؼ� min�� 3 ã��.
	...
	*/

	for (int i = 0; i < n; i++)
	{
		int min = arr[i];
		int location = i;
		for (int j = i; j < n; j++)
		{
			if (arr[j] < min)
			{
				min = arr[j];
				location = j;
			}
		}
		int tmp = arr[i];
		arr[i] = arr[location];
		arr[location] = tmp;
	}
}

void insertionSort(int n)
{
	//���� ����.  �´� �ڸ��� �����ϴ� ����. 1��°�� 0��°�� ���ؼ� �ڸ� ����ֱ�. 2��°�� 0~1��°�� ���ؼ� �ڸ� ����ֱ�. n��°�� 0~n-1������ ���ؼ� �ڸ� ����ֱ�. O(n^2)
	/*
	9 5 3 7 1
	(1) 5�� key. 9�� ��
		9 9 3 7 1�� ����.
		����for�� ���ͼ� 5 9 3 7 1

	(2) 3�� key. 9�� ��
		5 9 9 7 1�� ����.
		5�� ��.
		5 5 9 7 1�� ����.
		���� for�� ���ͼ� 3 5 9 7 1.

	(3) 7�� key. 9�� ��.
		3 5 9 9 1�� ����.
		5�� ��. key�� �� ŭ.
		���� for�� ���ͼ� 3 5 7 9 1.

	(4) 1�� key. 9�� ��.
		3 5 7 9 9
		7�� ��
		3 5 7 7 9
		5�� ��
		3 5 5 7 9
		3�� ��
		3 3 5 7 9
		���� for�� ���ͼ� 1 3 5 7 9

	*/
	int i, j;
	for (i = 1; i < n; i++)
	{
		int key = arr[i];
		for (j = i - 1; j >= 0; j--)
		{
			if (key < arr[j])
			{
				arr[j + 1] = arr[j];
			}
			else
			{
				break;
			}
		}
		arr[j + 1] = key;

	}
}

void bubbleSort(int n)
{
	//���� ����. 0,1��° ���ؼ� �´� �ڸ��� / 1,2��° ���ؼ� �´� �ڸ��� / 2,3��° ���ؼ� �´� �ڸ��� ... => 1ȸ���� ������ ���� ū ���� ���ĵǰ� �ȴ�.
	
	int i, j;
	for (i = n; i > 0; i--)
	{
		for (j = 0; j < i - 1; j++)
		{
			if (arr[j + 1] < arr[j])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;

			}
		}
	}
}

int main()
{
	int n;
	cin >> n;
	
	arr.resize(n,0);

	//�Է�
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	//selectionSort(n);
	//insertionSort(n);
	bubbleSort(n);



	//���
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\n";
	}

	return 0;
	

}

