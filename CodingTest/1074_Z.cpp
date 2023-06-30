#include <bits/stdc++.h>
using namespace std;

long long calculate(long long N, long long r, long long c)
{
	if (N == 1)
	{
		return 2 * r + c;
	}

	long long norm = pow(2, N - 1);
	long long count = 0;
	if (r >= norm)
		count += 2;
	if (c >= norm)
		count += 1;

	long long row = r >= norm ? r - norm : r;
	long long col = c >= norm ? c - norm : c;

	return count * norm * norm + calculate(N - 1, row, col);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long N, r, c;
	cin >> N >> r >> c;
	
	cout << calculate(N, r, c);
	
	return 0;
}