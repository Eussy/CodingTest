#include <bits/stdc++.h>

using namespace std;

int N;
int D[1001] = {0, };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	D[1] = 1;
	D[2] = 2;
	for (int i = 3; i <= N; i++) {
		D[i] = (D[i - 2] + D[i - 1]) % 10007;
	}

	cout << D[N];

	return 0;
}
