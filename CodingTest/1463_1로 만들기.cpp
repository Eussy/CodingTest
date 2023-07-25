#include <bits/stdc++.h>
using namespace std;

int a[1000001] = {0, };

int func(int n) {
	if (n == 1) return 0;
	if (a[n] != 0)
		return a[n];

	int a1 = 1000000, a2 = 1000000, a3 = 1000000;

	if (n % 3 == 0) {
		a1 = func(n / 3) + 1;
	}
	if (n % 2 == 0) {
		a2 = func(n / 2) + 1;
	}
	a3 = func(n - 1) + 1;

	a[n] = min(min(a1, a2), a3);

	return a[n];
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N;
	cin >> N;
	cout << func(N);

	return 0;
}

// 바킹독 풀이
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	a[1] = 0;
	for (int i = 2; i <= N; i++) {
		a[i] = a[i - 1] + 1;
		if (i % 2 == 0) a[i] = min(a[i], a[i / 2] + 1);
		if (i % 3 == 0) a[i] = min(a[i], a[i / 3] + 1);
	}
	cout << a[N];
}