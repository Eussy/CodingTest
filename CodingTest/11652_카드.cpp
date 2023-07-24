#include <bits/stdc++.h>
using namespace std;

int N;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	map<long long, long long> M;

	for (int i = 0; i < N; i++) {
		long long input;
		cin >> input;

		if (M.find(input) == M.end())
			M.insert({ input, 1 });
		else
			M[input]++;
	}

	long long answer = M.begin()->first;
	long long answer_count = M.begin()->second;

	for (auto& pair : M) {
		if (answer_count < pair.second) {
			answer = pair.first;
			answer_count = pair.second;
		}
	}

	cout << answer;

	return 0;
}