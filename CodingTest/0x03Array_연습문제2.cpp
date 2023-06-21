// ���� : �־��� ���� N�� int �迭 arr���� ���� 100�� ���� �ٸ� ��ġ�� �� ���Ұ� �����ϸ� 1��, �������� ������ 0�� ��ȯ�ϴ� �Լ�
//		  func2(int arr[], int N)�� �ۼ��϶�.
//		  arr�� �� ���� 0�̻� 100 �����̰� N�� 1000 �����̴�.

// func2({1, 52, 42}, 3) = 1,
// func2({50, 42}, 2) = 0,
// func2({4, 13, 63, 87}, 4) = 1




#include <bits/stdc++.h>
using namespace std;

// �ٽ��� O(n2)�� �ƴ�, O(N)�� �ð� ���⵵�� ���̴� ���� ����Ʈ�̴�.
int func2(int arr[], int N)
{
	int occur[101] = {0, };
	for (int i = 0; i < N; i++)
	{
		if (occur[100 - arr[i]] == 1)
			return 1;
		else
			occur[arr[i]] = 1;
	}
	return 0;
}

int main(void) {
	cin.tie(0);
	int arr[] = { 1, 52, 42 };
	cout << func2(arr, 3);
	int arr2[] = {50, 42};
	cout << func2(arr2, 2);
	int arr3[] = {4, 13, 63, 87};
	cout << func2(arr3, 4);
}	