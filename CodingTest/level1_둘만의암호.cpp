// 230206(월)
// https://school.programmers.co.kr/learn/courses/30/lessons/155652
// 문제 해설 : 정답률이 낮아 조금 무서웠던 문제였다. 하지만 천천히 skip 문자열을 제외한 채 set 컨테이너를 만들어 이터레이터로 풀렸더니 쉽게 풀렸다.
// 다른 사람 풀이를 보면 색다른 풀이 방법이다. 나머지를 이용해 skip에 없을 때만 + 해주는 방식으로 풀어냈다.

// 내 풀이
#include <string>
#include <set>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";

    // skip 문자들을 뺸 알파벳 배열
    set<char> vec;
    for (int i = 0; i < 26; i++)
    {
        if (skip.find('a' + i) == string::npos)
            vec.insert('a' + i);
    }

    for (char& ch : s)
    {
        auto iter = vec.find(ch);
        for (int i = 0; i < index; i++)
        {
            ++iter;
            if (iter == vec.end())
                iter = vec.begin();
        }
        answer += *iter;
    }
    return answer;
}

// 다른 사람 풀이
#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";

    for (auto v : s)
    {
        int t = 0;
        int c = v - 'a';
        while (t < index)
        {
            c++;
            v = (c % 26) + 'a';
            if (skip.find(v) == string::npos)
            {
                t++;
            }
        }
        answer += v;
    }
    return answer;
}