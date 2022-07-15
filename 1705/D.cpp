// Official: Correct
#include <iostream>
#include <vector>
using namespace std;
using pii = pair<int, int>;

int main(void)
{
    // read
    int tests, n;
    char ch;
    cin >> tests;
    for (int test = 0; test < tests; test++)
    {
        cin >> n;
        vector<pii> s, t;
        int start = -1;
        for (int i = 0; i < n; i++)
        {
            cin >> ch;
            if (ch == '0' && start != -1)
            {
                s.push_back(pii(start, i - 1));
                start = -1;
            }
            else if (ch == '1' && start == -1)
                start = i;
        }
        if (start != -1)
            s.push_back(pii(start, n - 1));
        start = -1;
        for (int i = 0; i < n; i++)
        {
            cin >> ch;
            if (ch == '0' && start != -1)
            {
                t.push_back(pii(start, i - 1));
                start = -1;
            }
            else if (ch == '1' && start == -1)
                start = i;
        }
        if (start != -1)
            t.push_back(pii(start, n - 1));

        // check valid
        bool changed = true;
        if (s.empty() && t.empty())
            cout << 0 << endl;
        else if (s.size() != t.size())
            cout << -1 << endl;
        else if ((s[0].first == 0) != (t[0].first == 0))
            cout << -1 << endl;
        else if ((s.back().second == n - 1) != (t.back().second == n - 1))
            cout << -1 << endl;
        else
            changed = false;
        if (changed)
            continue;

        // compute cost
        long long cost = 0;
        for (int i = 0; i < s.size(); i++)
            cost += abs(s[i].first - t[i].first) +
                    abs(s[i].second - t[i].second);
        cout << cost << endl;
    }
    return 0;
}