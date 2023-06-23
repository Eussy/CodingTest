#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;

    while (n >= a)
    {
        int divide = (n / a);
        n -= a * divide;
        n += b * divide;
        answer += b * divide;
    }

    return answer;
}