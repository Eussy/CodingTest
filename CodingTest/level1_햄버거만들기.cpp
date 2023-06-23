// 230203(��)
// https://school.programmers.co.kr/learn/courses/30/lessons/133502
// ���� �ؼ� & ���� �� : �̹� ������ �������� �ָ� �� �Ծ��µ�, ���Ϳ��� Ư�� �κ��� �������� �Ϳ� �ָ� �Ծ���. vector�� erase�� begin <= < end ������� ���� ��������
// �ٸ� �е��� Ǯ�̸� ����, vector �ϳ��� ���� vector�� .back()�� �̿��� ���ϰ� �ణ�� ���ð� ���� ������� �����ϴ� Ǯ�̰� �־���. �װ� ���� ȿ������ Ǯ�� ����. 
// 

// �� Ǯ��
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

// �ٸ� ��� �ڵ�
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