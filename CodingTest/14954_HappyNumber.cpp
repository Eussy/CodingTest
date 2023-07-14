#include <bits/stdc++.h>
using namespace std;
set<int> checking_set;
bool CheckHappyNumber(int n)
{
	if (n == 1)
		return true;
	if (checking_set.find(n) != checking_set.end())
		return false;

	checking_set.insert(n);

	int num = 0;

	while (n)
	{
		int a = n % 10;
		num += pow(a, 2);
		n /= 10;
	}

	return CheckHappyNumber(num);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int i = 0;
	cin >> i;
	
	if (CheckHappyNumber(i))
	{
		cout << "HAPPY";
	}
	else
	{
		cout << "UNHAPPY";
	}

	return 0;
}