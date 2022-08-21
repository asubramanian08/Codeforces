// 10:10 - 10:20
#include <iostream>
#include <map>
using namespace std;
using pii = pair<int, int>;

int main(void)
{
    int tests, n, k, x, y;
    cin >> tests;
    for (int test = 0; test < tests; test++)
    {
        cin >> n >> k;
        map<int, pii> range;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            auto loc = range.find(x);
            if (loc == range.end())
                range[x] = pii(i, i);
            else
                loc->second.second = i;
        }
        for (int i = 0; i < k; i++)
        {
            cin >> x >> y;
            if (range.find(x) == range.end() || range.find(y) == range.end())
                cout << "NO" << endl;
            else
                cout << (range[x].first <= range[y].second ? "YES" : "NO") << endl;
        }
    }
    return 0;
}