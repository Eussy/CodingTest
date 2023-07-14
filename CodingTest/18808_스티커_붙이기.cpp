#include <bits/stdc++.h>
using namespace std;

// N : 세로
// M : 가로
int N, M, K;
vector<vector<bool>> board;
vector<vector<vector<bool>>> stickers;

void input()
{
    cin >> N >> M >> K;
    board.resize(N);
    for (auto& vec : board)
        vec.resize(M, false);

    stickers.resize(K);

    for (int num = 0; num < K; num++)
    {
        int row, column;
        cin >> row >> column;
        stickers[num].resize(row);
        for (auto& vec : stickers[num])
            vec.resize(column);

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                int input;
                cin >> input;
                stickers[num][i][j] = input;
            }
        }
    }
}

bool IsPossible(int start_x, int start_y, vector<vector<bool>>& sticker)
{
    int height = sticker.size();
    int width = sticker[0].size();
    int max_y = start_y + height - 1;
    int max_x = start_x + width - 1;

    if (max_y >= N || max_x >= M)
        return false;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (sticker[y][x] && board[start_y + y][start_x + x])
                return false;
        }
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (sticker[y][x])
                board[start_y + y][start_x + x] = true;
        }
    }

    return true;
    
}

bool IsPossibleToPaste(vector<vector<bool>>& sticker)
{
    int height = sticker.size();
    int width = sticker[0].size();
    if (height > N || width > M)
        return false;
    
    for (int y = 0; y <= N - height; y++) {
        for (int x = 0; x <= M - width; x++) {
            if (IsPossible(x, y, sticker))
            {
                return true;
            }
        }
    }

    return false;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();

    for (int i = 0; i < K; i++)
    {
        int height = stickers[i].size();
        int width = stickers[i][0].size();
        // 0
        vector<vector<bool>> vec_0 = stickers[i];
        if (IsPossibleToPaste(vec_0)) continue;

        // 90
        vector<vector<bool>> vec_90;
        vec_90.resize(width);
        for (auto& vec : vec_90)
            vec.resize(height);
        for (int y = 0; y < width; y++) {
            for (int x = 0; x < height; x++) {
                vec_90[y][x] = stickers[i][height - x - 1][y];
            }
        }
        if (IsPossibleToPaste(vec_90)) continue;

        // 180
        vector<vector<bool>> vec_180;
        vec_180.resize(height);
        for (auto& vec : vec_180)
            vec.resize(width);
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                vec_180[y][x] = stickers[i][height - y - 1][x];
            }
        }
        if (IsPossibleToPaste(vec_180)) continue;

        // 270
        vector<vector<bool>> vec_270;
        vec_270.resize(width);
        for (auto& vec : vec_270)
            vec.resize(height);
        for (int y = 0; y < width; y++) {
            for (int x = 0; x < height; x++) {
                vec_270[y][x] = stickers[i][x][width - y - 1];
            }
        }
        if (IsPossibleToPaste(vec_270)) continue;
    }

    int answer = 0;
    for (auto& vec : board) {
        for (bool b : vec) {
            if (b)
                answer++;
        }
    }

    cout << answer;
}