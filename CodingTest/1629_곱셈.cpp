#include <bits/stdc++.h>
using namespace std;
long long mul(int a, int b, int c)
{
	if (b == 1) return a % c;

	long long val = mul(a, b / 2, c);

	val = val * val % c;

	if (b % 2 == 0)
		return val;
	else
		return val * a % c;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b, c;
	cin >> a >> b >> c;

	cout << mul(a, b, c);

	return 0;
}