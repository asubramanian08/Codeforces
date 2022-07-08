// Official: Correct
#include <iostream>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;
using pii = pair<int, int>;

int main(void)
{
    int tests, n, b;
    cin >> tests;
    for (int test = 0; test < tests; test++)
    {
        cin >> n;
        pair<int, pii> *perm = new pair<int, pii>[n];
        // pair(startTime, pair(endTime, pos#))
        for (int i = 1; i <= n; i++)
        {
            cin >> b;
            perm[i - 1].second.second = i - 1;
            perm[i - 1].first = i / (b + 1) + 1;
            assert(i / perm[i - 1].first == b);
            if (perm[i - 1].first != 1)
                assert(i / (perm[i - 1].first - 1) != b);
            perm[i - 1].second.first = b == 0 ? n + 5 : i / b;
            assert(i / perm[i - 1].second.first == b);
            if (b != 0)
                assert(i / (perm[i - 1].second.first + 1) != b);
        }
        sort(perm, perm + n);
        set<pii> s;
        int *ans = new int[n];
        for (int i = 1, pos = 0; i <= n; i++)
        {
            while (pos < n && perm[pos].first <= i)
                s.insert(perm[pos++].second);
            ans[s.begin()->second] = i;
            s.erase(s.begin());
        }
        for (int i = 0; i < n; i++)
            cout << ans[i] << ' ';
        cout << endl;
        delete[] perm;
        delete[] ans;
    }
    return 0;
}