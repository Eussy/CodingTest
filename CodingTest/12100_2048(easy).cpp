#include <bits/stdc++.h>

#define UP 0
#define DOWN 1
#define RIGHT 2
#define LEFT 3


using namespace std;

// N : 农扁
int N, answer = 0;
vector<vector<int>> board;

void func(int num, int dir, vector<vector<int>>& vec)
{
    if (num == 5)
    {
        for (auto& v : vec) {
            for (auto& n : v) {
                answer = max(answer, n);
            }
        }
        return;
    }

    auto this_vec = vec;
    switch (dir)
    {
    case UP:
        // 凯
        for (int i = 0; i < N; i++) {
            // 青
            vector<pair<bool, int>> temp;
            for (int j = 0; j < N; j++) {
                if (vec[j][i]) {
                    if (!temp.size()) {
                        temp.push_back({ false, vec[j][i] });
                    }
                    else {
                        auto& last_pair = temp[temp.size() - 1];
                        if (!last_pair.first && last_pair.second == vec[j][i]) {
                            last_pair.first = true;
                            last_pair.second *= 2;
                        }
                        else {
                            temp.push_back({ false, vec[j][i] });
                        }
                    }
                }
                

            }

            temp.resize(N);
            for (int j = 0; j < N; j++)
                this_vec[j][i] = temp[j].second;
        }

        break;
    case DOWN:
        // 凯
        for (int i = 0; i < N; i++) {
            vector<pair<bool, int>> temp;
            // 青
            for (int j = N - 1;  j >= 0; j--) {
                
                if (vec[j][i]) {
                    if (!temp.size()) {
                        temp.push_back({ false, vec[j][i] });
                    }
                    else {
                        auto& last_pair = temp[temp.size() - 1];
                        if (!last_pair.first && last_pair.second == vec[j][i]) {
                            last_pair.first = true;
                            last_pair.second *= 2;
                        }
                        else {
                            temp.push_back({ false, vec[j][i] });
                        }
                    }
                }
            }

            temp.resize(N);
            for (int j = 0; j < N; j++)
                this_vec[N - 1 - j][i] = temp[j].second;
        }
        break;
    case RIGHT:
        // 青
        for (int i = 0; i < N; i++) {
            vector<pair<bool, int>> temp;
            // 凯
            for (int j = N - 1; j >= 0; j--) {
                if (vec[i][j]) {
                    if (!temp.size()) {
                        temp.push_back({ false, vec[i][j] });
                    }
                    else {
                        auto& last_pair = temp[temp.size() - 1];
                        if (!last_pair.first && last_pair.second == vec[i][j]) {
                            last_pair.first = true;
                            last_pair.second *= 2;
                        }
                        else {
                            temp.push_back({ false, vec[i][j] });
                        }
                    }
                }
            }

            temp.resize(N);
            for (int j = 0; j < N; j++)
                this_vec[i][N - 1 - j] = temp[j].second;
        }
        break;
    case LEFT:
        // 青
        for (int i = 0; i < N; i++) {
            vector<pair<bool, int>> temp;
            // 凯
            for (int j = 0; j < N; j++) {
                if (vec[i][j]) {
                    if (!temp.size()) {
                        temp.push_back({ false, vec[i][j] });
                    }
                    else {
                        auto& last_pair = temp[temp.size() - 1];
                        if (!last_pair.first && last_pair.second == vec[i][j]) {
                            last_pair.first = true;
                            last_pair.second *= 2;
                        }
                        else {
                            temp.push_back({ false, vec[i][j] });
                        }
                    }
                }
            }

            temp.resize(N);
            for (int j = 0; j < N; j++)
                this_vec[i][j] = temp[j].second;
        }
        break;
    }

    for (int i = 0; i < 4; i++)
        func(num + 1, i, this_vec);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    board.resize(N);
    for (auto& vec : board)
        vec.resize(N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < 4; i++)
        func(0, i, board);

    cout << answer;

}