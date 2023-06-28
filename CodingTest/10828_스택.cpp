#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int count;
	cin >> count;

	stack<int> st;

	for (int i = 0; i < count; i++)
	{
		string s;
		int num = 0;
		cin >> s;
		
		if (s == "push") {
			cin >> num;
			st.push(num);
		}
		if (s == "pop") {
			if (st.empty()) {
				cout << -1 << "\n"; 
				continue;
			}

			cout << st.top() << "\n";
			st.pop();
		}
		if (s == "size") {
			cout << st.size() << "\n";
		}
		if (s == "empty") {
			cout << st.empty() << "\n";
		}
		if (s == "top") {
			if (st.empty()) {
				cout << -1 << "\n"; 
				continue;
			}
				
			cout << st.top() << "\n";
		}
	}
}