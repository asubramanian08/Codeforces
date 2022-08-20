// Official: Wrong on test 4
#include <iostream>
#include <algorithm>
using namespace std;
using pii = pair<long long, long long>;

int main(void)
{
    long long n, q;
    cin >> n >> q;
    long long *arr = new long long[n];
    for (long long i = 0; i < n; i++)
        arr[i] = 0;
    long long *maxArr = new long long[n];
    for (long long i = 0; i < n; i++)
        maxArr[i] = 0;
    pair<pii, long long> *qs = new pair<pii, long long>[q];
    for (long long i = 0; i < q; i++)
    {
        long long temp1, temp2;
        cin >> temp1 >> temp2 >> qs[i].second;
        qs[i].first.first = min(temp1, temp2) - 1;
        qs[i].first.second = max(temp1, temp2) - 1;
    }
    sort(qs, qs + q);

    for (long long j = 0; j < 35; j++)
        for (long long i = 0; i < q; i++)
            if (!(qs[i].second & (1 << j)))
            {
                maxArr[qs[i].first.first] |= (1 << j);
                maxArr[qs[i].first.second] |= (1 << j);
            }

    for (long long j = 0; j < 35; j++)
        for (long long i = 0; i < q; i++)
            if ((qs[i].second & (1 << j)) &&
                ((arr[qs[i].first.first] & (1 << j)) == 0))
            {
                if (maxArr[qs[i].first.second] & (1 << j))
                    arr[qs[i].first.first] |= (1 << j);
                else
                    arr[qs[i].first.second] |= (1 << j);
            };
    for (long long i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << endl;
    return 0;
}