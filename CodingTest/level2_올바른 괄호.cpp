// 230623(금)
// https://school.programmers.co.kr/learn/courses/30/lessons/12909?language=cpp
// 문제 해설 & 느낀 점
// 큐를 써도 풀 수 있고, 안써도 풀수 있기에 큐를 쓸까말까 고민을 했지만, 그냥 써보는 연습을 위해 쓰기로 했다.
// 다른 사람의 풀이를 보니 스택을 사용해 (를 넣고 )가 나오면 빼버리고 마지막에 개수로 문제를 해결하는 식으로 문제를 풀었는데, 그런 식도 굉장히 괜찮은 것 같다.
// 

// 내 풀이
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

// 다른 사람 풀이
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