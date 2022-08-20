#include <iostream>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

int main(void)
{
    int n, q;
    cin >> n >> q;
    int *arr = new int[n];
    int *zeros = new int[n];
    for (int i = 0; i < n; i++)
        arr[i] = 0, zeros[i] = (1 << 30) - 1;
    pair<pii, int> *cond = new pair<pii, int>[q];
    for (int i = 0; i < q; i++)
    {
        cin >> cond[i].first.first >> cond[i].first.second >> cond[i].second;
        if (--cond[i].first.first > --cond[i].first.second)
            swap(cond[i].first.first, cond[i].first.second);
    }
    sort(cond, cond + q);
    for (int i = 0; i < q; i++)
    {
        zeros[cond[i].first.first] &= cond[i].second;
        zeros[cond[i].first.second] &= cond[i].second;
    }
    for (int i = 0; i < q; i++)
        arr[cond[i].first.first] |= ~zeros[cond[i].first.second] & cond[i].second;
    for (int i = 0; i < q; i++)
        arr[cond[i].first.second] |= ~arr[cond[i].first.first] & cond[i].second;
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << endl;
}