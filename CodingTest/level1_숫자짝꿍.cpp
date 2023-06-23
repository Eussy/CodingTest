#include <string>
#include <algorithm>
#include <set>

using namespace std;

string solution(string X, string Y) {
    string answer = "";

    for (int i = 0; i < 10; i++)
    {
        int countX = 0;
        int countY = 0;
        for (char letter : X)
        {
            int num = letter - '0';
            if (num == i)
                countX++;
        }

        for (char letter : Y)
        {
            int num = letter - '0';
            if (num == i)
                countY++;
        }

        int finalCount = min(countX, countY);
        if (finalCount > 0)
        {
            char ch1 = i + '0';
            for (int j = 0; j < finalCount; j++)
                answer += ch1;
        }
    }

    if (answer.length() == 0)
        return "-1";

    sort(answer.begin(), answer.end(), greater<>());

    if (answer[0] == '0')
        return "0";

    return answer;
}