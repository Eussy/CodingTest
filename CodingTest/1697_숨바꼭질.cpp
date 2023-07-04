#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int n = 0;
int k = 0;

int arr[100002];
queue<int> cur_queue;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// Get Input
	cin >> n >> k;
	fill(arr, arr + 100001, -1);
	arr[n] = 0;
	cur_queue.push(n);
	while (arr[k] == -1)
	{
		int pos = cur_queue.front();
		cur_queue.pop();
		for (int i : {pos - 1, pos + 1, pos * 2})
		{
			int next_pos = i;
			
			if (next_pos > 100000 || next_pos < 0) continue;
			if (arr[next_pos] != -1) continue;

			arr[next_pos] = arr[pos] + 1;
			cur_queue.push(next_pos);
		}
	}

	cout << arr[k];
	return 0;
}