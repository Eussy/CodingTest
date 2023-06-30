#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string input;
	cin >> input;

	stack<char> S;
	int count = 0;
	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] == '(')
			S.push('(');
		else if (input[i] == ')' && input[i - 1] == '(')
		{
			count += S.size() - 1;
			S.pop();
		}
			
		else if (input[i] == ')')
		{
			count += 1;
			S.pop();
		}
			
	}
	cout << count;
	return 0;
}