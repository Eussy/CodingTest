#include <bits/stdc++.h>
using namespace std;

int n = 10;
int arr[1000001] = { 15, 25, 22, 357, 16, 23, -53, 12, 46, 3 };

void QuickSort(int st, int en)
{
	if (en - st <= 1) return;
	int pivot = arr[st];
	int l = st + 1;
	int r = en - 1;
	while (true)
	{
		while (arr[l] <= pivot && l + 1 <= en)
			l++;
		while (arr[r] >= pivot && r - 1 >= st)
			r--;

		if (l > r) break;

		swap(arr[l], arr[r]);
	}
	swap(arr[r], arr[st]);

	QuickSort(st, r);
	QuickSort(r + 1, en);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	QuickSort(0, 10);

	return 0;
}