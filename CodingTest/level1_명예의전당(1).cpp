// 230129(��)
// https://school.programmers.co.kr/learn/courses/30/lessons/138477
// ���� �ؼ� & ���� ��
// �̹� ������ iterator�� end()�Լ����� ���������ڰ� �����ϴٴ� ����� �Ȱ� ���� ������� �ƴϾ��� �ʹ�.
// ���̵��� ���� �����̾��� �� ������ ��� Ǫ�� �� ���� �̻ܱ� �����ϴٰ� �� �ð��� �ɷȴ� �� ����.

// �� Ǯ��
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