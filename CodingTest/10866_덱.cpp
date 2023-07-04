#include <bits/stdc++.h>
using namespace std;

/*
push_front X: 정수 X를 덱의 앞에 넣는다.
push_back X: 정수 X를 덱의 뒤에 넣는다.
pop_front: 덱의 가장 앞에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
pop_back: 덱의 가장 뒤에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 덱에 들어있는 정수의 개수를 출력한다.
empty: 덱이 비어있으면 1을, 아니면 0을 출력한다.
front: 덱의 가장 앞에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
back: 덱의 가장 뒤에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
*/

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int count;
	cin >> count;

	deque<int> D;

	for (int i = 0; i < count; i++)
	{
		string s;
		int num = 0;
		cin >> s;

		if (s == "push_front") {
			cin >> num;
			D.push_front(num);
		}
		if (s == "push_back") {
			cin >> num;
			D.push_back(num);
		}
		if (s == "pop_front") {
			if (D.empty()) {
				cout << -1 << "\n";
				continue;
			}

			cout << D.front() << "\n";
			D.pop_front();
		}
		if (s == "pop_back") {
			if (D.empty()) {
				cout << -1 << "\n";
				continue;
			}

			cout << D.back() << "\n";
			D.pop_back();
		}
		if (s == "size") {
			cout << D.size() << "\n";
		}
		if (s == "empty") {
			cout << D.empty() << "\n";
		}
		if (s == "front") {
			if (D.empty()) {
				cout << -1 << "\n";
				continue;
			}

			cout << D.front() << "\n";
		}
		if (s == "back") {
			if (D.empty()) {
				cout << -1 << "\n";
				continue;
			}

			cout << D.back() << "\n";
		}
	}
}