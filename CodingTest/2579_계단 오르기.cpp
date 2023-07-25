#include <bits/stdc++.h>
using namespace std;


// Ç®ÀÌ***
https://www.notion.so/0x10-2c2e8d8369a7472290cee3dc8942d0c1?pvs=4#058e58c9db3243b9bcdb6aafe10545d5


int N;
vector<int> steps;
map<pair<int, bool>, int> max_value;

int func(int n, bool cons) {
	if (n >= N) return 0;
	
	if (n == N - 1)
		return steps[n];
	
	if (max_value.find({ n, cons }) != max_value.end())
		return max_value[{n, cons}];

	if (cons) {
		if (int ret = func(n + 2, 0))
		{
			int result = steps[n] + ret;
			max_value.insert({ {n, cons}, result });
			return result;
		}
		else
			return 0;
	}
		
	else {
		if (int greater = max(func(n + 1, true), func(n + 2, false))) {
			int result = steps[n] + greater;
			max_value.insert({ {n, cons}, result });
			return result;
		}
		else
			return 0;
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for(int i = 0; i < N; i++) {
		int input;
		cin >> input;
		steps.push_back(input);
	}

	cout << max(func(0, false), func(1, false));

	return 0;
}
