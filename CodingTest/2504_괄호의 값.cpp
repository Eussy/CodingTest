#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string input;
	cin >> input;

	stack<char> S;
	int total[100] = { 0, };
	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] == '(' || input[i] == '[')
			S.push(input[i]);

		else if (input[i] == ')')
		{
			if (S.empty() || S.top() != '(')
			{
				cout << 0;
				return 0;
			}

			if (input[i - 1] == '(')
				total[S.size() - 1] += 2;
			else
			{
				total[S.size() - 1] += total[S.size()] * 2;
				total[S.size()] = 0;
			}
			
			S.pop();
		}

		else if (input[i] == ']')
		{
			if (S.empty() || S.top() != '[')
			{
				cout << 0;
				return 0;
			}

			if (input[i - 1] == '[')
				total[S.size() - 1] += 3;
			else
			{
				total[S.size() - 1] += total[S.size()] * 3;
				total[S.size()] = 0;
			}

			S.pop();
		}

	}
	cout << total[0];
	return 0;
}