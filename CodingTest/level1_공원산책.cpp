// 230504(목)
// https://school.programmers.co.kr/learn/courses/30/lessons/172928
// 문제 해설 & 느낀 점 : 이중 반복문을 통해서 찾는게 많아서 조금 까다로웠는데, 코드가 길어지긴 했지만 첫 풀이대로 풀려서 다행이다
// 다른 사람의 풀이를 보니 방향을 미리 매핑을 해서 따로 방향체크를 안한 풀이가 있었다. 매우 좋은 풀이인 것 같다.

// 내 풀이
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;

    int height = park.size();
    int width = park[0].size();

    int x = 0;
    int y = 0;

    bool bBreak = false;
    for (int i = 0; i < park.size(); i++)
    {
        if (bBreak)
            break;
        for (int j = 0; j < park[i].size(); j++)
        {
            if (park[i][j] == 'S')
            {
                x = j;
                y = i;
                bBreak = false;
                break;
            }
        }
    }

    for (string& str : routes)
    {
        bool pass = true;
        int count = str[2] - '0';
        if (str[0] == 'N')
        {
            if (y - count < 0)
                continue;

            for (int i = y - 1; i >= y - count; i--)
            {
                if (park[i][x] == 'X')
                {
                    pass = false;
                    break;
                }
            }

            if (!pass)
                continue;

            y -= count;
        }
        else if (str[0] == 'S')
        {
            if (y + count >= height)
                continue;

            for (int i = y + 1; i <= y + count; i++)
            {
                if (park[i][x] == 'X')
                {
                    pass = false;
                    break;
                }
            }

            if (!pass)
                continue;

            y += count;
        }
        else if (str[0] == 'W')
        {
            if (x - count < 0)
                continue;

            for (int i = x - 1; i >= x - count; i--)
            {
                if (park[y][i] == 'X')
                {
                    pass = false;
                    break;
                }
            }

            if (!pass)
                continue;

            x -= count;
        }
        else if (str[0] == 'E')
        {
            if (x + count >= width)
                continue;

            for (int i = x + 1; i <= x + count; i++)
            {
                if (park[y][i] == 'X')
                {
                    pass = false;
                    break;
                }
            }

            if (!pass)
                continue;

            x += count;
        }
    }

    answer.push_back(y);
    answer.push_back(x);

    return answer;
}

// 다른 사람 풀이
#include <map>
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
map<char, int> mapping = {
    {'E', 0}, {'W', 1}, {'S', 2}, {'N', 3}
};

vector<int> solution(vector<string> park, vector<string> routes) {
    int cx, cy;
    for (int i = 0; i < park.size(); ++i) {
        for (int j = 0; j < park[i].size(); ++j) {
            if (park[i][j] == 'S') {
                tie(cx, cy) = { i, j };
                break;
            }
        }
    }

    for (int i = 0; i < routes.size(); ++i) {
        int num = routes[i][2] - '0';
        int dir = mapping[routes[i][0]];

        int nx = cx, ny = cy;
        while (num--) {
            nx += dx[dir];
            ny += dy[dir];

            if (!(nx >= 0 && nx < park.size()) || !(ny >= 0 && ny < park[0].size())) break;
            if (park[nx][ny] == 'X') break;
        }

        if (num < 0) {
            cx = nx;
            cy = ny;
        }
    }
    return { cx, cy };
}