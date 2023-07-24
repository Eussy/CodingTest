#include <bits/stdc++.h>
using namespace std;

int N;
vector<string> V;

bool custon_sort(const string& a, const string& b) {
	if (a.size() != b.size()) return a.size() < b.size() ? true : false;

	int a_sum = 0, b_sum = 0;
	for (auto& ch : a) {
		if (ch >= '0' && ch <= '9')
			a_sum += ch - '0';
	}

	for (auto& ch : b) {
		if (ch >= '0' && ch <= '9')
			b_sum += ch - '0';
	}

	if (a_sum != b_sum) return a_sum < b_sum ? true : false;

	return a < b;
}

int main(void) {
	ios::sync_with_stdio(0);		
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;
		V.push_back(input);
	}

	sort(V.begin(), V.end(), custon_sort);

	for (auto& s : V)
		cout << s << "\n";

	return 0;
}