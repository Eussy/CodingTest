// 230209(목)
// https://school.programmers.co.kr/learn/courses/30/lessons/150370
// 문제 해설 & 느낀 점 : string을 나누고 substr 메소드를 많이 사용해 이해도를 늘릴 수 있는 좋은 알고리즘 문제였다. 
// 정답율이 낮아서 조금 어려울 것이라고 느꼈는데 막상 마무리하니 생각보다 그렇게 어렵지 않게 풀었다.

// 내 풀이
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;

    map<string, int> standard;
    vector<pair<string, string>> datas;

    int curYear = stoi(today.substr(0, 4));
    int curMonth = stoi(today.substr(5, 2));
    int curDay = stoi(today.substr(8, 2));

    for (auto str : terms)
        standard.insert({ str.substr(0, 1), stoi(str.substr(2)) });

    for (auto str : privacies)
        datas.push_back({ str.substr(11), str.substr(0, 10) });


    for (int idx = 0; idx < datas.size(); idx++)
    {
        int expireValue = standard[datas[idx].first];
        string date = datas[idx].second;
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));

        if (expireValue / 12 > 0)
        {
            int addYear = expireValue / 12;
            year += addYear;
            expireValue -= addYear * 12;
        }

        month += expireValue;
        if (month > 12)
        {
            year++;
            month -= 12;
        }


        if (curYear < year)
            continue;
        else if (curYear > year)
        {
            answer.push_back(idx + 1);
            continue;
        }

        if (curMonth < month)
            continue;
        else if (curMonth > month)
        {
            answer.push_back(idx + 1);
            continue;
        }

        if (curDay < day)
            continue;
        else
        {
            answer.push_back(idx + 1);
            continue;
        }
    }

    return answer;
}