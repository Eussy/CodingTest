// 230202(목)
// https://school.programmers.co.kr/learn/courses/30/lessons/140108
// 문제 해설 & 느낀 점
// 이번 문제는 사실 문제를 꼼꼼히 읽었으면 조금 더 편하게 풀었을 것 같다. 예시를 한 번 꼼꼼하게 읽어보는 게 중요할 것 같다.
// 또한 반복문에 while을 사용할 지, do while을 사용할지, for를 사용할지를 결정하는 것도 굉장히 중요한 요소 중 하나 인 것 같다.

// 내 풀이
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;

    int index = 0;
    while (index < s.length())
    {
        int X = 0;
        int notX = 0;

        char ch = s.at(index);
        do 
        {
            if (s.at(index) == ch)
                X++;
            else
                notX++;

            index++;

            if (index == s.length())
                return ++answer;

        } while (X != notX);

        answer++;
    }

    return answer;
}