#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 }; // 상하좌우 네 방향을 의미

int width = 0;
int height = 0;

string input[102];
int road[102][102];
queue <pair<int, int>> cur_queue;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string buffer;
	memset(road, -1, sizeof(road));

	// Get Input
	cin >> height >> width;
	for (int i = 0; i < height; i++)
	{
		cin >> input[i];
	}

	// Logic
	road[0][0] = 1;
	cur_queue.push({ 0, 0 });
	while (cur_queue.size())
	{
		auto pos = cur_queue.front();
		cur_queue.pop();
		auto dist = road[pos.Y][pos.X];
		for (int i = 0; i < 4; i++)
		{
			int nx = pos.X + dx[i];
			int ny = pos.Y + dy[i];
			if (nx < 0 || nx >= width || ny < 0 || ny >= height) continue;
			if (input[ny][nx] == '0') continue;
			// if already visited, Check new dist
			if (road[ny][nx] != -1 && road[ny][nx] <= dist + 1) continue;
			road[ny][nx] = dist + 1;
			cur_queue.push({ nx, ny });
		}
	}

	cout << road[max(0, height - 1)][max(0, width - 1)];

	return 0;
}