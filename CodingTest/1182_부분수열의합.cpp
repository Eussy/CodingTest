#include <bits/stdc++.h>
using namespace std;

int N, S;
int answer = 0;
int arr[22];
bool isvisited[22];

void func(int num)
{
	if (num == N)
	{
		int sum = 0;
		bool valid = false;

		for (int i = 0; i < N; i++) {
			if (isvisited[i])
			{
				sum += arr[i];
				if(valid == false)
					valid = true;
			}
		}
		if (sum == S && valid)
			answer++;
		return;
	}

	isvisited[num] = true;
	func(num + 1);
	isvisited[num] = false;
	func(num + 1);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	

	cin >> N >> S;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	func(0);


	cout << answer;
	return 0;
}