// 230623(��)
// https://school.programmers.co.kr/learn/courses/30/lessons/12951
// ���� �ؼ� & ���� ��
// �� ������ tolower, toupper�� �� ���ڸ� ���� �ٲ��ִ� ���� �ƴ�, ���ڸ� ��ȯ�Ѵٴ� ���� ���� �߿��� �� ���Ҵ�.
// �ٸ� ����� Ǯ�̴� ���ڿ��� �� �� ���鼭 �ٲ۴ٴ� ������ ��� ���� ���� Ǯ�̿���. �ð� ���⵵�� ���� �پ���.
// ���� �������� ��ü ���ڿ��� �Ҵ��ϴ� ���� �ƴ�, �ϳ��� ���ϴ� �͵� ȿ������ �� ����.

// �� Ǯ��
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";

    transform(s.begin(), s.end(), s.begin(), ::tolower);

    s[0] = toupper(s[0]);
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            s[i + 1] = toupper(s[i + 1]);
        }
    }

    answer = s;

    return answer;
}


// �ٸ� ��� Ǯ��
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";

    answer += toupper(s[0]);
    for (int i = 1; i < s.size(); i++)
        s[i - 1] == ' ' ? answer += toupper(s[i]) : answer += tolower(s[i]);

    return answer;
}
