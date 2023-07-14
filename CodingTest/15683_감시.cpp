#include <bits/stdc++.h>
using namespace std;

// N : 세로
// M : 가로
int N, M;
vector<vector<int>> board;
vector<pair<int, pair<int, int>>> cctv;
int answer = 10000000;

void up(vector<vector<bool>>& vec, int x, int y)
{
    for (int i = y; i >= 0; i--) {
        if (board[i][x] == 6)
            break;
        vec[i][x] = false;
    }
}

void down(vector<vector<bool>>& vec, int x, int y)
{
    for (int i = y; i < N; i++) {
        if (board[i][x] == 6)
            break;
        vec[i][x] = false;
    }
}

void left(vector<vector<bool>>& vec, int x, int y)
{
    for (int i = x; i >= 0; i--) {
        if (board[y][i] == 6)
            break;
        vec[y][i] = false;
    }
}

void right(vector<vector<bool>>& vec, int x, int y)
{
    for (int i = x; i < M; i++) {
        if (board[y][i] == 6)
            break;
        vec[y][i] = false;
    }
}

void func(int num, vector<vector<bool>> vec)
{
    if (num == cctv.size())
    {
        int value = 0;
        for (auto& v : vec) {
            for (auto b : v) {
                if (b)
                    value++;
            }
        }

        answer = min(value, answer);
        return;
    }

    auto vec_ = vec;
    int x = cctv[num].second.first;
    int y = cctv[num].second.second;
    switch (cctv[num].first)
    {
    case 1:
        // 상
        vec_ = vec;
        up(vec_, x, y);
        func(num + 1, vec_);
        // 하
        vec_ = vec;
        down(vec_, x, y);
        func(num + 1, vec_);
        // 좌
        vec_ = vec;
        left(vec_, x, y);
        func(num + 1, vec_);
        // 우
        vec_ = vec;
        right(vec_, x, y);
        func(num + 1, vec_);
        break;
    case 2:
        // 가로
        vec_ = vec;
        right(vec_, x, y);
        left(vec_, x, y);
        func(num + 1, vec_);
        // 세로
        vec_ = vec;
        up(vec_, x, y);
        down(vec_, x, y);
        func(num + 1, vec_);
        break;
    case 3:
        // 상우
        vec_ = vec;
        up(vec_, x, y);
        right(vec_, x, y);
        func(num + 1, vec_);

        // 우하
        vec_ = vec;
        right(vec_, x, y);
        down(vec_, x, y);
        func(num + 1, vec_);

        // 하좌
        vec_ = vec;
        down(vec_, x, y);
        left(vec_, x, y);
        func(num + 1, vec_);

        // 좌상
        vec_ = vec;
        left(vec_, x, y);
        up(vec_, x, y);
        func(num + 1, vec_);
        break;
    case 4:
        // 상우하
        vec_ = vec;
        up(vec_, x, y);
        right(vec_, x, y);
        down(vec_, x, y);
        func(num + 1, vec_);

        // 우하좌
        vec_ = vec;
        right(vec_, x, y);
        down(vec_, x, y);
        left(vec_, x, y);
        func(num + 1, vec_);

        // 하좌상
        vec_ = vec;
        down(vec_, x, y);
        left(vec_, x, y);
        up(vec_, x, y);
        func(num + 1, vec_);

        // 좌상우
        vec_ = vec;
        left(vec_, x, y);
        up(vec_, x, y);
        right(vec_, x, y);
        func(num + 1, vec_);
        break;
    case 5:
        vec_ = vec;
        up(vec_, x, y);
        down(vec_, x, y);
        right(vec_, x, y);
        left(vec_, x, y);
        func(num + 1, vec_);
        break;
    }

}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<vector<bool>> bool_board;

    cin >> N >> M;
    board.resize(N);
    bool_board.resize(N);
    for (auto& vec : board)
        vec.resize(M, true);
    for (auto& vec : bool_board)
        vec.resize(M, true);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int input;
            cin >> input;

            if (input == 0)
                continue;
            else if (input == 6)
            {
                bool_board[i][j] = false;
                board[i][j] = 6;
            }
            else
            {
                bool_board[i][j] = false;
                cctv.push_back({ input, {j, i} });
            }
        }
    }

    func(0, bool_board);

    cout << answer;
}