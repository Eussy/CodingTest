// 230203(금)
// https://school.programmers.co.kr/learn/courses/30/lessons/133502
// 문제 해설 & 느낀 점 : 이번 문제는 생각보다 애를 좀 먹었는데, 벡터에서 특정 부분을 빼버리는 것에 애를 먹었다. vector의 erase는 begin <= < end 범위라는 것을 주의하자
// 다른 분들의 풀이를 보니, vector 하나를 만들어서 vector의 .back()을 이용해 비교하고 약간의 스택과 같은 방식으로 관리하는 풀이가 있었다. 그게 제일 효율적인 풀이 같다. 
// 

// 내 풀이
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    // 1 2 3 1

    vector<int>::iterator begin;
    vector<int>::iterator end;
    int flag = 0;

    for (auto iter = ingredient.begin(); iter != ingredient.end(); )
    {
        if (*iter == 1 && flag == 3)
        {
            answer++;
            end = iter;
            ingredient.erase(begin, end + 1);
            iter = ingredient.begin();
            flag = 0;
            continue;
        }
        else if (*iter == 1)
        {
            flag = 1;
            begin = iter;
        }

        else if (*iter == flag + 1)
            flag = *iter;
        else
            flag = 0;

        ++iter;

    }
    return answer;
}

// 다른 사람 코드
int solution(vector<int> ingredient) {
    int answer = 0;
    vector<int> v = { -1 };
    for (int x : ingredient) {
        if (v.back() == 1 && x == 2) v.back() = 12;
        else if (v.back() == 12 && x == 3) v.back() = 123;
        else if (v.back() == 123 && x == 1) answer++, v.pop_back();
        else v.push_back(x);
    }

    return answer;
}