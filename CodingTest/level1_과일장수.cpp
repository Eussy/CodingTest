// 230129(일)
// https://school.programmers.co.kr/learn/courses/30/lessons/135808
// 문제 해설 : 처음에 봤을 때 어려웠는데, 간단히 풀리는 문제였다.
//             중간에 m - count를 안해줘서 틀렸었는데, 머리 풀기에 괜찮은 수준이었던 것 같다.

#include <string>
#include <vector>

using namespace std;

int solution(int k, int m, vector<int> scores) {
    int answer = 0;
    vector<int> fruitBox;
    fruitBox.resize(k, 0);
    
    for (auto score : scores)
        fruitBox[score - 1]++;


    int count = 0;
    for (int i = k - 1; i >= 0; )
    {
        if (fruitBox[i] + count >= m)
        {
            fruitBox[i] -= m - count;
            answer += m * (i + 1);
            count = 0;
        }
        else
        {
            count += fruitBox[i];
            fruitBox[i] = 0;
            i--;
        }
    }


    return answer;
}