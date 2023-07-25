#include <bits/stdc++.h>

using namespace std;

int N, M;
int D[1000001] = { 0, };
int P[1000001] = { 0, };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	
	D[1] = 0;
	P[1] = 0;

	for (int i = 2; i <= N; i++)
	{
		D[i] = D[i - 1] + 1;
		P[i] = i - 1;

		if (i % 2 == 0 && D[i / 2] + 1 < D[i])
		{
			D[i] = D[i / 2] + 1;
			P[i] = i / 2;
		}
		if (i % 3 == 0 && D[i / 3] + 1 < D[i]) {
			D[i] = D[i / 3] + 1;
			P[i] = i / 3;
		}
	}

	cout << D[N] << "\n";
	while (N) {
		cout << N << " ";
		N = P[N];
	}

	return 0;
}
