// https://school.programmers.co.kr/learn/courses/30/lessons/178871
// ���� �ؼ�
// ������ ���ڿ� ��ü �������� �˾Ҵµ�, ���Ϳ��� �˰��� find �Լ��� ���� ã���� �ð� �ʰ��� ���� �ٸ� ����� �����غ��ٰ� ���ͳ� �˻��� �غ���
// map�� ����� ����ϴ� ��������. �������� �������, ���� map �� ���� ����� ����ߴµ�, �ٸ� ������� �ϳ��� ����� ������ Ǫ�� ����� ã�Ƴ��� �� ���Ҵ�.

// �� Ǯ��

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

// �ٸ� ��� �ؼ�

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