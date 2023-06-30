#include <bits/stdc++.h>
using namespace std;

/*
push_front X: ���� X�� ���� �տ� �ִ´�.
push_back X: ���� X�� ���� �ڿ� �ִ´�.
pop_front: ���� ���� �տ� �ִ� ���� ����, �� ���� ����Ѵ�. ����, ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
pop_back: ���� ���� �ڿ� �ִ� ���� ����, �� ���� ����Ѵ�. ����, ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
size: ���� ����ִ� ������ ������ ����Ѵ�.
empty: ���� ��������� 1��, �ƴϸ� 0�� ����Ѵ�.
front: ���� ���� �տ� �ִ� ������ ����Ѵ�. ���� ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
back: ���� ���� �ڿ� �ִ� ������ ����Ѵ�. ���� ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
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