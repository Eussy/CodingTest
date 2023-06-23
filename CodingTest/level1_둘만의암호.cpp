// 230206(��)
// https://school.programmers.co.kr/learn/courses/30/lessons/155652
// ���� �ؼ� : ������� ���� ���� �������� ��������. ������ õõ�� skip ���ڿ��� ������ ä set �����̳ʸ� ����� ���ͷ����ͷ� Ǯ�ȴ��� ���� Ǯ�ȴ�.
// �ٸ� ��� Ǯ�̸� ���� ���ٸ� Ǯ�� ����̴�. �������� �̿��� skip�� ���� ���� + ���ִ� ������� Ǯ��´�.

// �� Ǯ��
#include <string>
#include <set>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";

    // skip ���ڵ��� �A ���ĺ� �迭
    set<char> vec;
    for (int i = 0; i < 26; i++)
    {
        if (skip.find('a' + i) == string::npos)
            vec.insert('a' + i);
    }

    for (char& ch : s)
    {
        auto iter = vec.find(ch);
        for (int i = 0; i < index; i++)
        {
            ++iter;
            if (iter == vec.end())
                iter = vec.begin();
        }
        answer += *iter;
    }
    return answer;
}

// �ٸ� ��� Ǯ��
#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";

    for (auto v : s)
    {
        int t = 0;
        int c = v - 'a';
        while (t < index)
        {
            c++;
            v = (c % 26) + 'a';
            if (skip.find(v) == string::npos)
            {
                t++;
            }
        }
        answer += v;
    }
    return answer;
}