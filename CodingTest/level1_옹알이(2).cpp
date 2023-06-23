// 230131(화)
// https://school.programmers.co.kr/learn/courses/30/lessons/133499
// 문제 해설 & 느낀 점
// 이번 문제는 조금 어렵긴 했다. 나는 중복을 해결하는 방법을 인덱스를 사용해서 조금 어렵게 풀어냈는데,
// 다른 분의 풀이를 보니 그냥 빼면서 플래그를 세워서 플래그가 다르면 더하는 방법을 사용하셨다. 많이 배웠다.

// 내 풀이
#include <string>
#include <vector>

using namespace std;

int countStr(string sentence, string str)
{
    int count = 0;
    for (int index = 0; index < sentence.size(); )
    {
        int nextIndex = sentence.find(str, index);
        if (nextIndex == string::npos)
            break;
        else if (index != 0 && nextIndex == index)
            return -1;
        else
        {
            index = nextIndex + str.size();
            count += str.size();
        }
    }
    return count;
}

int solution(vector<string> babbling) {
    int answer = 0;

    vector<string> possible({ "aya", "ye", "woo", "ma" });

    for (auto sentence : babbling)
    {
        int count = 0;
        for (auto str : possible)
        {
            int result = countStr(sentence, str);
            if (result == 0)
                continue;
            if (result == -1)
                break;
            else
                count += result;
        }
        if (sentence.size() == count)
            answer++;
    }

    return answer;
}

// 다른 사람 풀이
#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling)
{
    int answer = 0;

    for (string s : babbling)
    {
        int flag = 0; bool j = true;
        for (int i = 0; i < s.length(); i++)
        {
            if (s.substr(i, 3) == "aya" && flag != 1) { flag = 1; i += 2; }
            else if (s.substr(i, 2) == "ma" && flag != 2) { flag = 2; i += 1; }
            else if (s.substr(i, 3) == "woo" & flag != 3) { flag = 3; i += 2; }
            else if (s.substr(i, 2) == "ye" && flag != 4) { flag = 4; i += 1; }
            else { j = false; break; }
        }
        if (j == true) answer++;
    }

    return answer;
}