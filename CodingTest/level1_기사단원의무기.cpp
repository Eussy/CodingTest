// 230130(��)
// https://school.programmers.co.kr/learn/courses/30/lessons/136798
// ���� �ؼ� & ���� ��
// �� Ǯ�� ��ü�� ��� ���ͳݿ��� �� Ǯ�̸� �״�� ���� ���̶� �״��� �ǹ̰� ����.
// �ð� ���⵵�� ���̱� ���ؼ� �������� �������� ���� ���ε�, �����ٱ����� ����� ���ϸ� �� �������� ������ ���� �̿��ؼ� ������ Ǯ����.
// ������ ���������� �� Ǯ�̿����� �ڵ带 ���� �˰����� �迭�� �̸� �����ΰ� 1���� ����鿡 count�� �ϳ��� �÷��ִ� ����� ���ߴ�.
// �� Ǯ�̰� �ð� ���⵵�� ������ �پ��� �� Ǯ�̺��ٵ� �ð��� �ξ� �پ�� ���� ������.

// �� Ǯ��
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

// ������ ���� Ǯ�� : https://www.inflearn.com/course/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98
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