// Official:
#include <iostream>
using namespace std;

int main(void)
{
    long long tests, n, k, b, s;
    cin >> tests;
    while (tests--)
    {
        cin >> n >> k >> b >> s;
        long long toRemove = s - b * k;
        if (toRemove < 0 || n * (k - 1) < toRemove)
            cout << -1 << endl;
        else
        {
            for (int i = 1; i < n; i++)
            {
                long long extra = min(k - 1, toRemove);
                s -= extra;
                toRemove -= extra;
                cout << extra << ' ';
            }
            cout << s << endl;
        }
    }
    return 0;
}