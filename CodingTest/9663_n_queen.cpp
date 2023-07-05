#include <bits/stdc++.h>
using namespace std;

int n;
bool visited1[1000001];
bool visited2[1000001];
bool visited3[1000001];
int answer = 0;

void func(int num)
{
	if (num == n) {
		answer++;
		return;
	}

	for (int i = 0; i < n ; i++)
	{
		if (visited1[i] || visited2[i + num] || visited3[i - num + n - 1])
			continue;
		visited1[i] = true;
		visited2[i + num] = true;
		visited3[i - num + n - 1] = true;
		func(num + 1);
		visited1[i] = false;
		visited2[i + num] = false;
		visited3[i - num + n - 1] = false;
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	func(0);

	cout << answer;
	return 0;
}