#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<int> vec1{ 5, 3, 2, 1, 7 };
    vector<int> vec2{ 2, 7, 9, 1, 2, 3 };
    sort(vec1.begin(), vec1.end());
    vec1.resize(vec1.size() + vec2.size());

    sort(vec2.begin(), vec2.end());

    int idx1 = vec2.size();
    int idx2 = 0;

    // 1. vec1의 원소를 뒤로 미룬다.
    for (int i = 0; i < vec1.size() - vec2.size(); i++) 
        vec1[i + vec2.size()] = vec1[i];

    // 2. 두 배열을 합친다.
    for (int i = 0; i < vec1.size(); i++)
    {
        if (idx1 >= vec1.size())            
            vec1[i] = vec2[idx2++];
        else if (idx2 >= vec2.size())       
            vec1[i] = vec1[idx1++];
        else if (vec1[idx1] <= vec2[idx2])  
            vec1[i] = vec1[idx1++];
        else                               
            vec1[i] = vec2[idx2++];
    }

    return 0;
}