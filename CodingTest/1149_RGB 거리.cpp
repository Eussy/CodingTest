#include <bits/stdc++.h>
#define R 0
#define G 1
#define B 2

using namespace std;

int N;
int D[1001][3];
int V[1001][3];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) 
		cin >> V[i][R] >> V[i][G] >> V[i][B];

	D[0][R] = V[0][R];
	D[0][G] = V[0][G];
	D[0][B] = V[0][B];
	for (int i = 1; i < N; i++) {
		D[i][R] = V[i][R] + min(D[i - 1][G], D[i - 1][B]);
		D[i][G] = V[i][G] + min(D[i - 1][R], D[i - 1][B]);
		D[i][B] = V[i][B] + min(D[i - 1][R], D[i - 1][G]);
	}

	cout << min(min(D[N - 1][R], D[N - 1][G]), D[N - 1][B]);

	return 0;
}
