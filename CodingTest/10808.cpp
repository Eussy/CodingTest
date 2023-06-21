#include <bits/stdc++.h>
using namespace std;

int main(void) {
	cin.tie(0);

	string input;
	getline(cin, input);

	int alpha[26] = { 0, };
	for (char a : input){
		alpha[a-'a']++;
	}

	for (int i = 0; i < 26; i++) {
		cout << alpha[i] << " ";
	}
}