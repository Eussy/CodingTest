#include <bits/stdc++.h>

#define X first
#define Y second

using namespace std;

int N, M;
int answer = 10000000;
vector<pair<int, int>> house;
vector<pair<int, int>> store;

int func(vector<int> comb) {

    vector<int> min_dist;
    min_dist.resize(house.size(), 1000000);

    for (int i = 0; i < M; i++) {
        auto store_pos = store[comb[i]];
        for (int j = 0; j < house.size(); j++) {
            int dx = abs(store_pos.X - house[j].X);
            int dy = abs(store_pos.Y - house[j].Y);
            int dist = dx + dy;
            min_dist[j] = min(min_dist[j], dist);
        }
    }

    int total_dist = 0;
    for (auto& dist : min_dist)
        total_dist += dist;

    return total_dist;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int input;
            cin >> input;
            if (input == 1)
                house.push_back({ j, i });
            else if (input == 2)
                store.push_back({ j, i });
        }
    }

    vector<int> temp;
    temp.resize(store.size(), 1);
    for (int i = 0; i < store.size() - M; i++)
        temp[i] = 0;

    do {
        vector<int> combi;
        for (int i = 0; i < temp.size(); i++) {
            if (temp[i])
                combi.push_back(i);
        }

        answer = min(answer, func(combi));

    } while (next_permutation(temp.begin(), temp.end()));

    cout << answer;
}