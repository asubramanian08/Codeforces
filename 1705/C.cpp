// Official: Correct
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using pii = pair<long long, long long>;

int main(void)
{
    // read
    int tests, n, c, q;
    cin >> tests;
    for (int test = 0; test < tests; test++)
    {
        string s;
        vector<pii> v;
        long long l, r, pos;
        pii add;
        cin >> n >> c >> q;
        cin >> s;

        // set ranges (minIdx, toChange)
        long long startIdx = s.size();
        for (int i = 0; i < c; i++)
        {
            cin >> l >> r;
            l--, r--;
            add.first = startIdx;
            add.second = startIdx - l;
            startIdx += r - l + 1;
            v.push_back(add);
        }

        // answer queries
        for (int i = 0; i < q; i++)
        {
            cin >> pos;
            pos--;
            for (int j = v.size() - 1; j >= 0; j--)
                if (pos >= v[j].first)
                    pos -= v[j].second;
            cout << s[pos] << endl;
        }
    }
    return 0;
}