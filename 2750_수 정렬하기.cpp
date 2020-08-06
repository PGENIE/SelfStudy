#include<iostream>
#include<vector>

using namespace std;
//정렬 : 선택, 삽입, 버블
vector<int> arr;


void selectionSort(int n)
{
	//선택 정렬. 자리 작은거부터 선택해서 그 자리에 맞는 애를 찾아온다. O(n^2)
	/*
	9 5 3 7 1
	(1) 0번째 자리에 제일 작은 애는? => 전부 조회해서 min값 1 찾음.
	(2) 1번째 자리에 제일 작은 애는? => 0번째 애 제외하고 1~n-1번째 조회해서 min값 3 찾음.
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
	//삽입 정렬.  맞는 자리에 삽입하는 정렬. 1번째랑 0번째랑 비교해서 자리 집어넣기. 2번째랑 0~1번째랑 비교해서 자리 집어넣기. n번째랑 0~n-1번쨰랑 비교해서 자리 집어넣기. O(n^2)
	/*
	9 5 3 7 1
	(1) 5가 key. 9와 비교
		9 9 3 7 1로 변경.
		안쪽for문 나와서 5 9 3 7 1

	(2) 3이 key. 9와 비교
		5 9 9 7 1로 변경.
		5와 비교.
		5 5 9 7 1로 변경.
		안쪽 for문 나와서 3 5 9 7 1.

	(3) 7이 key. 9와 비교.
		3 5 9 9 1로 변경.
		5와 비교. key가 더 큼.
		안쪽 for문 나와서 3 5 7 9 1.

	(4) 1이 key. 9와 비교.
		3 5 7 9 9
		7과 비교
		3 5 7 7 9
		5와 비교
		3 5 5 7 9
		3과 비교
		3 3 5 7 9
		안쪽 for문 나와서 1 3 5 7 9

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
	//버블 정렬. 0,1번째 비교해서 맞는 자리로 / 1,2번째 비교해서 맞는 자리로 / 2,3번째 비교해서 맞는 자리로 ... => 1회차가 끝나면 제일 큰 값은 정렬되게 된다.
	
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

	//입력
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	//selectionSort(n);
	//insertionSort(n);
	bubbleSort(n);



	//출력
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\n";
	}

	return 0;
	

}

