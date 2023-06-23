// https://school.programmers.co.kr/learn/courses/30/lessons/178871
// 문제 해설
// 간단한 문자열 교체 문제인줄 알았는데, 벡터에서 알고리즘 find 함수를 통해 찾으면 시간 초과가 떠서 다른 방법을 생각해보다가 인터넷 검색을 해보니
// map을 만들어 사용하는 문제였다. 생각보다 어려웠고, 나는 map 두 개를 만들어 사용했는데, 다른 사람들은 하나로 사용해 문제를 푸는 방법도 찾아내는 것 같았다.

// 내 풀이

#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    map<int, string> ranking_int;
    map<string, int> ranking_str;

    for (int i = 0; i < players.size(); i++)
    {
        ranking_int.insert({ i + 1, players[i] });
        ranking_str.insert({ players[i], i + 1 });
    }

    for (int i = 0; i < callings.size(); i++)
    {
        string name = callings[i];
        int bef_rank = ranking_str[name];
        int aft_rank = bef_rank - 1;
        string ranker_name = ranking_int[aft_rank];

        ranking_int[aft_rank] = name;
        ranking_int[bef_rank] = ranker_name;

        ranking_str[name] = aft_rank;
        ranking_str[ranker_name] = bef_rank;
    }

    vector<string> answer;
    for (auto& pair : ranking_int)
    {
        answer.push_back(pair.second);
    }

    return answer;
}

// 다른 사람 해설

vector<string> solution(vector<string> players, vector<string> callings)
{
    vector<string> answer;

    map<string, int> m;
    for (int i = 0; i < players.size(); i++)
        m[players[i]] = i;

    int s1, s2;
    string tmp;
    for (int i = 0; i < callings.size(); i++)
    {
        s2 = m[callings[i]]; s1 = s2 - 1;
        m[players[s2]]--; m[players[s1]]++;
        tmp = players[s2];
        players[s2] = players[s1];
        players[s1] = tmp;
    }

    answer = players;

    return answer;
}