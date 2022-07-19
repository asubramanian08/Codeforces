// 6:08 - 6:52
#include <iostream>
using namespace std;
using pii = pair<long long, long long>;

bool divBy(long long a, long long b) { return a % b == 0; }

int main(void)
{
    int tests, n, m, k;
    cin >> tests;
    for (int test = 0; test < tests; test++)
    {
        cin >> n >> m;
        pii *a = new pii[n];
        for (int i = 0; i < n; i++)
            cin >> a[i].first;
        cin >> k;
        pii *b = new pii[k];
        for (int i = 0; i < k; i++)
            cin >> b[i].first;

        for (int i = 0; i < n; i++)
        {
            a[i].second = 1;
            while (divBy(a[i].first, m))
            {
                a[i].first /= m;
                a[i].second *= m;
            }
        }
        for (int i = 0; i < k; i++)
        {
            b[i].second = 1;
            while (divBy(b[i].first, m))
            {
                b[i].first /= m;
                b[i].second *= m;
            }
        }

        bool works = true;
        int bIdx = 0;
        for (int i = 0; i < n && works; i++)
        {
            while (bIdx < k && b[bIdx].first == a[i].first && a[i].second > 0)
            {
                long long remove = min(a[i].second, b[bIdx].second);
                a[i].second -= remove;
                b[bIdx].second -= remove;
                if (b[bIdx].second == 0)
                    bIdx++;
            }
            if (a[i].second != 0)
                works = false;
        }
        if (works)
            works = bIdx == k;
        cout << (works ? "Yes" : "No") << endl;
    }
    return 0;
}