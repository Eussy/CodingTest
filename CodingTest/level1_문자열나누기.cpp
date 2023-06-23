// 230202(��)
// https://school.programmers.co.kr/learn/courses/30/lessons/140108
// ���� �ؼ� & ���� ��
// �̹� ������ ��� ������ �Ĳ��� �о����� ���� �� ���ϰ� Ǯ���� �� ����. ���ø� �� �� �Ĳ��ϰ� �о�� �� �߿��� �� ����.
// ���� �ݺ����� while�� ����� ��, do while�� �������, for�� ��������� �����ϴ� �͵� ������ �߿��� ��� �� �ϳ� �� �� ����.

// �� Ǯ��
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;

    int index = 0;
    while (index < s.length())
    {
        int X = 0;
        int notX = 0;

        char ch = s.at(index);
        do 
        {
            if (s.at(index) == ch)
                X++;
            else
                notX++;

            index++;

            if (index == s.length())
                return ++answer;

        } while (X != notX);

        answer++;
    }

    return answer;
}