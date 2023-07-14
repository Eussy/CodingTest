#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> answer;
vector<int> isused;

void func(int num)
{
    if (num == m)
    {
        for (auto a : answer)
            cout << a << " ";
        cout << "\n";
        return;
    }
        
    for (int i = 0; i < n; i++)
    {
        if (isused[i])
            continue;
        answer.push_back(i + 1);
        isused[i] = true;
        func(num + 1);
        isused[i] = false;
        answer.pop_back();
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    isused.resize(n);
    func(0);
}