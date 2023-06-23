#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;

    int strSize = p.size();

    for (int i = 0; i < t.size() - strSize + 1; i++)
    {
        string str = t.substr(i, strSize);
        if (str <= p)
            answer++;
    }

    return answer;
}