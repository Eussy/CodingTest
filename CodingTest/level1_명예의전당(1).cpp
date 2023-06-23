// 230129(일)
// https://school.programmers.co.kr/learn/courses/30/lessons/138477
// 문제 해설 & 느낀 점
// 이번 문제는 iterator에 end()함수에도 증감연산자가 가능하다는 사실을 안게 가장 배울점이 아니었나 싶다.
// 난이도는 쉬운 수준이었던 것 같지만 어떻게 푸는 게 가장 이쁠까 생각하다가 좀 시간이 걸렸던 것 같다.

// 내 풀이
#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(int k, vector<int> scores) {
    vector<int> answer;
    multiset<int,greater<>> winnerList;
    for (int score : scores)
    {
        winnerList.insert(score);

        auto iter = winnerList.begin();
        for (int count = 0; count < k; count++)
        {
            if (iter == --winnerList.end() || count == k - 1)
            {
                answer.push_back(*iter);
                break;
            }
                
            ++iter;
        }
    }

    return answer;
}