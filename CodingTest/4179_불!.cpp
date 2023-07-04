#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 }; // 상하좌우 네 방향을 의미

int width = 0;
int height = 0;
char maze[1001][1001] = { 0, };
int fire[1001][1001];
int jihun[1001][1001];
queue <pair<int, int>> fire_queue;
queue <pair<int, int>> jihun_queue;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string buffer;
	memset(fire, -1, sizeof(fire));
	memset(jihun, -1, sizeof(jihun));

	// Get Input
	cin >> height >> width;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			cin >> maze[i][j];
			if (maze[i][j] == 'J')
			{
				jihun[i][j] = 0;
				jihun_queue.push({ j, i });
			}
				
			if (maze[i][j] == 'F')
			{
				fire[i][j] = 0;
				fire_queue.push({ j, i });
			}
				
		}
	}

	// Logic

	// Fire
	while (fire_queue.size())
	{
		auto pos = fire_queue.front();
		fire_queue.pop();
		auto dist = fire[pos.Y][pos.X];
		for (int i = 0; i < 4; i++)
		{
			int nx = pos.X + dx[i];
			int ny = pos.Y + dy[i];
			if (nx < 0 || nx >= width || ny < 0 || ny >= height) continue;
			if (maze[ny][nx] == '#' || fire[ny][nx] != -1) continue;

			fire[ny][nx] = dist + 1;
			fire_queue.push({ nx, ny });
		}
	}

	// Jihun
	while (jihun_queue.size())
	{
		auto pos = jihun_queue.front();
		jihun_queue.pop();
		auto dist = jihun[pos.Y][pos.X];
		for (int i = 0; i < 4; i++)
		{
			int nx = pos.X + dx[i];
			int ny = pos.Y + dy[i]; 
			if (nx < 0 || nx == width || ny < 0 || ny == height)
			{
				cout << dist + 1;
				return 0;
			}
			if (maze[ny][nx] == '#' || jihun[ny][nx] != -1) continue;
			if (fire[ny][nx] != -1 && fire[ny][nx] <= dist + 1) continue;
			
			jihun[ny][nx] = dist + 1;
			jihun_queue.push({ nx, ny });
		}
	}

	cout << "IMPOSSIBLE";

	return 0;
}