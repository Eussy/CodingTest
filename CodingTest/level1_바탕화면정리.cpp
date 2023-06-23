// https://school.programmers.co.kr/learn/courses/30/lessons/161990
// 문제 해설
// 벡터로 풀어도 되지만 귀찮아서 수정하지는 않았다. 최대 최소 값을 구하는 간단하게 풀리는 문제였던 것 같다.

// 내 풀이
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> wallpaper) {

    vector<int> answer;
    map<pair<int, int>, bool> files;
    for (int y = 0; y < wallpaper.size(); y++)
    {
        for (int x = 0; x < wallpaper[y].size(); x++)
        {
            if (wallpaper[y][x] == '#')
                files.insert({ {y,x}, true });
        }
    }

    answer.resize(4);
    answer[0] = 9999;
    answer[1] = 9999;
    answer[2] = 0;
    answer[3] = 0;

    for (auto& pair : files)
    {
        int x = pair.first.first;
        int y = pair.first.second;
        answer[0] = min(answer[0], x);
        answer[1] = min(answer[1], y);
        answer[2] = max(answer[2], x + 1);
        answer[3] = max(answer[3], y + 1);
    }

    return answer;
}