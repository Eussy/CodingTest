// https://school.programmers.co.kr/learn/courses/30/lessons/142086
// ���� �ؼ�
// ������ ���ڿ� ��������.

// �� Ǯ��

#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    answer.resize(s.size(), -1);
    for (int i = s.size() - 1; i >= 0; i--)
    {
        int count = 0; 
        for (int j = i - 1; j >= 0; j--)
        {
            ++count;
            if (s[i] == s[j])
            {
                answer[i] = count;
                break;
            }
        }
        
    }
        return answer;
}