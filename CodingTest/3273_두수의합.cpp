#include <bits/stdc++.h>
using namespace std;

queue<int> cur_queue;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, x;
	int answer = 0;
	vector<int> vec;
	cin >> n;

	vec.resize(n);

	for (int i = 0; i < n; i++)
		cin >> vec[i];

	cin >> x;

	sort(vec.begin(), vec.end());

	int l = 0;
	int r = n - 1;
	while (true)
	{
		int result = vec[l] + vec[r];
		if (result == x) {
			answer++;
			l++;
			r--;
		}
		else if (result < x) {
			l++;
		}
		else {
			r--;
		}

		if (l >= r)
			break;
	}

	cout << answer;

	return 0;
}