#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int N;
vector<vector<int>>	house_map;

int func(int x, int y) {
	int cnt = 0;
	queue<pair<int, int>> Q;

	house_map[y][x] = false;
	Q.push({ x, y });

	while (!Q.empty())
	{
		auto node = Q.front();
		Q.pop();
		cnt++;

		for (int i = 0; i < 4; i++) {
			int pos_x = node.X + dx[i];
			int pos_y = node.Y + dy[i];

			if (pos_x < 0 || pos_x >= N || pos_y < 0 || pos_y >= N)
				continue;

			if (house_map[pos_y][pos_x]) {
				house_map[pos_y][pos_x] = false;
				Q.push({ pos_x, pos_y });
			}
		}
	}

	return cnt;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	multiset<int> S;

	cin >> N;
	house_map.resize(N);
	for (auto& vec : house_map)
		vec.resize(N);

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < N; j++) {
			house_map[i][j] = str[j] - '0';
		}
	}

	// 노드들 순회
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (house_map[i][j])
				S.insert(func(j, i));
		}
	}

	cout << S.size() << "\n";

	for(auto& num : S)
		cout << num << "\n";

	return 0;
}