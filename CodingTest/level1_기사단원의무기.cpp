// 230130(월)
// https://school.programmers.co.kr/learn/courses/30/lessons/136798
// 문제 해설 & 느낀 점
// 내 풀이 자체는 사실 인터넷에서 본 풀이를 그대로 베낀 것이라 그다지 의미가 없다.
// 시간 복잡도를 줄이기 위해서 제곱근의 형식으로 구한 것인데, 제곱근까지의 약수를 구하면 그 제곱또한 약수라는 것을 이용해서 문제를 풀었다.
// 하지만 인프런에서 본 풀이에서는 코드를 보면 알겠지만 배열을 미리 만들어두고 1부터 배수들에 count를 하나씩 올려주는 방식을 택했다.
// 이 풀이가 시간 복잡도가 굉장히 줄어들어 내 풀이보다도 시간이 훨씬 줄어든 것이 보였다.

// 내 풀이
#include <string>
#include <vector>

using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0;

    vector<int> knight_weapon_power;
    knight_weapon_power.resize(number, 0);
    for (int i = 1; i <= number; i++)
    {
        for (int j = 1; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                knight_weapon_power[i - 1]++;
                if (j * j < i)
                {
                    knight_weapon_power[i - 1]++;
                }
            }

            if (knight_weapon_power[i - 1] > limit)
            {
                knight_weapon_power[i - 1] = power;
                break;
            }
        }
    }

    for (auto power2 : knight_weapon_power)
    {
        answer += power2;
    }
    return answer;
}

// 인프런 강의 풀이 : https://www.inflearn.com/course/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98
#include <string>
#include <vector>

using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0;

    vector<int> knight_weapon_power;
    knight_weapon_power.resize(number, 0);
    for (int i = 1; i <= number; i++)
    {
        for (int j = i; j <= number; j = j + i)
        {
            if (j % i == 0)
            {
                knight_weapon_power[j - 1]++;
            }
        }
    }

    for (auto power2 : knight_weapon_power)
    {
        if (power2 > limit)
            answer += power;
        else
            answer += power2;
    }
    return answer;
}