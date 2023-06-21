#include <bits/stdc++.h>
using namespace std;

int main(void) {
	cin.tie(0);

	string str;
	string num;
	getline(cin, str);
	getline(cin, num);
	int n = stoi(num);
	list<char> list(str.begin(), str.end());
	auto iter = list.end();
	for (int i = 0; i < n; i++)
	{
		string input;
		getline(cin, input);
		if (input[0] == 'L') { 
			if (iter != list.begin()) 
				--iter; 
		}
		if (input[0] == 'D') { 
			if (iter != list.end()) 
				++iter;	
		}
		if (input[0] == 'B') { 
			if (iter != list.begin()) 
				iter = list.erase(--iter); 
		}
		if (input[0] == 'P') { 
			list.insert(iter, input[2]);
		}
	}
	str.assign(list.begin(), list.end());
	cout << str;

	return 0;
}