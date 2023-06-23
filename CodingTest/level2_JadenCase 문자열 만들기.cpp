// 230623(금)
// https://school.programmers.co.kr/learn/courses/30/lessons/12951
// 문제 해설 & 느낀 점
// 이 문제는 tolower, toupper가 그 문자를 직접 바꿔주는 것이 아닌, 문자를 반환한다는 것이 가장 중요한 것 같았다.
// 다른 사람의 풀이는 문자열을 한 번 돌면서 바꾼다는 점에서 배울 점이 많은 풀이였다. 시간 복잡도가 많이 줄어든다.
// 또한 마지막에 전체 문자열을 할당하는 것이 아닌, 하나씩 더하는 것도 효과적인 것 같다.

// 내 풀이
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";

    transform(s.begin(), s.end(), s.begin(), ::tolower);

    s[0] = toupper(s[0]);
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            s[i + 1] = toupper(s[i + 1]);
        }
    }

    answer = s;

    return answer;
}


// 다른 사람 풀이
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";

    answer += toupper(s[0]);
    for (int i = 1; i < s.size(); i++)
        s[i - 1] == ' ' ? answer += toupper(s[i]) : answer += tolower(s[i]);

    return answer;
}
