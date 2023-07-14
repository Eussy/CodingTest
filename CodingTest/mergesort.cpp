#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& vec, int st, int en)
{
    int size = en - st;
    int mid = (st + en) / 2;

    vector<int> tmp;
    tmp.resize(size);

    int idx1 = st;
    int idx2 = mid;
    // 두 배열을 합친다.
    for (int i = 0; i < size; i++)
    {
        if (idx1 >= mid)
            tmp[i] = vec[idx2++];
        else if (idx2 >= en)
            tmp[i] = vec[idx1++];
        else if (vec[idx1] <= vec[idx2])
            tmp[i] = vec[idx1++];
        else
            tmp[i] = vec[idx2++];
    }

    for (int i = 0; i < tmp.size(); i++)
        vec[i + st] = tmp[i];

}

void merge_sort(vector<int>& vec, int st, int en)
{
    if (en - st <= 1)
        return;

    int mid = (en + st) / 2;
    merge_sort(vec, st, mid);
    merge_sort(vec, mid, en);
    merge(vec, st, en);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> vec1{ 5, 3, 2, 1, 7 };
    
    merge_sort(vec1, 0, 5);

    return 0;
}