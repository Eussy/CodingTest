#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 }; // 상하좌우 네 방향을 의미

vector<vector<int>> input;
vector<vector<int>> visited;
queue<pair<int, int>> cur_queue;
int height = 0;
int width = 0;
int num = 0;
int best = 0;

vector<string> split(string str, char paramiter)
{
	vector<string> splited;
	stringstream ss(str);
	string buffer;

	while (getline(ss, buffer, paramiter))
	{
		splited.push_back(buffer);
	}

	return splited;
}

void BFS(int x, int y)
{
	visited[y][x] = 1;
	cur_queue.push({ x, y });

	num++;
	int breadth = 0;
	while (cur_queue.size() != 0)
	{
		auto pos = cur_queue.front();
		cur_queue.pop();
		breadth++;
		for (int i = 0; i < 4; i++)
		{
			int nx = pos.X + dx[i];
			int ny = pos.Y + dy[i];
			if (nx < 0 || nx >= width || ny < 0 || ny >= height) continue;
			if (!input[ny][nx] || visited[ny][nx]) continue;
			visited[ny][nx] = 1;
			cur_queue.push({ nx, ny });
		}
	}
	if (breadth > best)
		best = breadth;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// Variables
	string buffer;

	// Receive Input
	getline(cin, buffer);
	auto splited = split(buffer, ' ');
	height = stoi(splited[0]);
	width = stoi(splited[1]);

	input.resize(height); 
	visited.resize(height);
	for (int i = 0; i < height; i++)
	{
		input[i].resize(width);
		visited[i].resize(width);
	}

	for (int i = 0; i < height; i++)
	{
		getline(cin, buffer);
		splited = split(buffer, ' ');
		for (int j = 0; j < width; j++)
			input[i][j] = stoi(splited[j]);
	}

	// Logic
	// 1. Find Start Node
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			// If find new node, push to queue and Execute BFS
			if (input[y][x] && !visited[y][x])
			{
				BFS(x, y);
			}
				

		}
	}

	cout << num << "\n" << best << "\n";
	return 0;
}