#include <bits/stdc++.h>

using namespace std;

int N, M;
int nums[100001] = { 0, };
int sums[100001] = { 0, };
vector<pair<int, int>> ranges;
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<int> answer;
	cin >> N >> M;
	for(int i = 1; i <= N; i++)
		cin >> nums[i];

	sums[1] = nums[1];
	for (int i = 2; i <= N; i++) {
		sums[i] = sums[i - 1] + nums[i];
	}

	for (int i = 0; i < M; i++) {
		int input1, input2;
		cin >> input1 >> input2;

		ranges.push_back({ input1, input2 });
	}

	for (int i = 0; i < M; i++) {
		cout << sums[ranges[i].second] - sums[ranges[i].first - 1] << "\n";
	}
	
	return 0;
}
