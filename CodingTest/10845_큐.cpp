#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int count;
	cin >> count;

	queue<int> Q;

	for (int i = 0; i < count; i++)
	{
		string s;
		int num = 0;
		cin >> s;

		if (s == "push") {
			cin >> num;
			Q.push(num);
		}
		if (s == "pop") {
			if (Q.empty()) {
				cout << -1 << "\n";
				continue;
			}

			cout << Q.front() << "\n";
			Q.pop();
		}
		if (s == "size") {
			cout << Q.size() << "\n";
		}
		if (s == "empty") {
			cout << Q.empty() << "\n";
		}
		if (s == "front") {
			if (Q.empty()) {
				cout << -1 << "\n";
				continue;
			}

			cout << Q.front() << "\n";
		}
		if (s == "back") {
			if (Q.empty()) {
				cout << -1 << "\n";
				continue;
			}

			cout << Q.back() << "\n";
		}
	}
}