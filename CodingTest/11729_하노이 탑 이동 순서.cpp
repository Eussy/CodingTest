#include <bits/stdc++.h>
using namespace std;

vector<string> strs;

int move(int num, int from, int to, int temp)
{
	string str;
	if (num == 1)
	{
		str = to_string(from) + " " + to_string(to);
		strs.push_back(str);
		return 1;
	}

	int count = 0;

	count += move(num - 1, from, temp, to);

	count++; 
	str = to_string(from) + " " + to_string(to);
	strs.push_back(str);

	count += move(num - 1, temp, to, from);

	return count;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a;
	cin >> a;

	cout << move(a, 1, 3, 2) << "\n";

	for (auto& str : strs)
		cout << str << "\n";

	return 0;
}