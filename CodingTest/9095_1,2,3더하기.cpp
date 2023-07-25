#include <bits/stdc++.h>
using namespace std;

int func(int n) {
	if (n <= 0) return 0;

	if (n == 1) return 1; 
	if (n == 2) return 2; 
	if (n == 3) return 4;

	return func(n - 1) + func(n - 2) + func(n - 3);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	
	vector<int> V;

	while (N--) {
		int input;
		cin >> input;
		cout << func(input) << "\n";
	}

	return 0;
}
