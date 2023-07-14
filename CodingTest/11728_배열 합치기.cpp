#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	vector<int> vec1, vec2;

	cin >> N >> M;
	vec1.resize(N);
	vec2.resize(M);

	for (int i = 0; i < N; i++)
		cin >> vec1[i];
	for (int i = 0; i < M; i++)
		cin >> vec2[i];

	vector<int> answer;

	int index1 = 0, index2 = 0;

	while (answer.size() < N + M)
	{
		if (index1 >= vec1.size()) {
			answer.push_back(vec2[index2++]);
			continue;
		}
		if (index2 >= vec2.size()) {
			answer.push_back(vec1[index1++]);
			continue;
		}
			
		if (vec1[index1] <= vec2[index2])
			answer.push_back(vec1[index1++]);
		else
			answer.push_back(vec2[index2++]);
	}

	for (auto& num : answer)
		cout << num << " ";

	return 0;
}