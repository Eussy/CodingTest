// 230129(��)
// https://school.programmers.co.kr/learn/courses/30/lessons/135808
// ���� �ؼ� : ó���� ���� �� ������µ�, ������ Ǯ���� ��������.
//             �߰��� m - count�� �����༭ Ʋ�Ⱦ��µ�, �Ӹ� Ǯ�⿡ ������ �����̾��� �� ����.

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