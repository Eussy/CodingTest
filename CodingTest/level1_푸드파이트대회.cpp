// https://school.programmers.co.kr/learn/courses/30/lessons/134240
// ���� �ؼ�
// Ǯ��� ������ ��������. ���ڿ��� �� ���� ���� ������ ���� �����ָ� ��

// �� Ǯ��

#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    string front = "";
    string back = "";
    for (int count = 1; count < food.size(); count++) 
    {
        int eachCount = food[count] / 2;
        for (int j = 0; j < eachCount; j++)
        {
            front += to_string(count);
            back = to_string(count) + back;
        }
    }

    answer = front + "0" + back;
    return answer;
}
