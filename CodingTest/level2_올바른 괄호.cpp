// 230623(��)
// https://school.programmers.co.kr/learn/courses/30/lessons/12909?language=cpp
// ���� �ؼ� & ���� ��
// ť�� �ᵵ Ǯ �� �ְ�, �Ƚᵵ Ǯ�� �ֱ⿡ ť�� ����� ����� ������, �׳� �Ẹ�� ������ ���� ����� �ߴ�.
// �ٸ� ����� Ǯ�̸� ���� ������ ����� (�� �ְ� )�� ������ �������� �������� ������ ������ �ذ��ϴ� ������ ������ Ǯ���µ�, �׷� �ĵ� ������ ������ �� ����.
// 

// �� Ǯ��
#include <string>
#include <queue>

using namespace std;

bool solution(string s)
{
    int open = 0;
    int close = 0;

    queue<char> q;

    for (auto chr : s)
    {
        q.push(chr);
    }

    while (q.size() != 0)
    {
        auto chr = q.front();
        q.pop();

        chr == '(' ? open++ : close++;

        if (open < close)
            return false;
    }

    if (open == close)
        return true;
    else
        return false;
}

// �ٸ� ��� Ǯ��
#include<string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack <char> st;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') st.push(s[i]);
        else if (s[i] == ')') {
            if (st.empty() || st.top() != '(') {
                answer = false; break;
            }
            st.pop();
        }
    }
    if (!st.empty()) answer = false;
    return answer;
}