// Official: Correct
#include <iostream>
#include <cassert>
using namespace std;
using pii = pair<int, int>;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tests, n;
    cin >> tests;
    while (tests--)
    {
        cin >> n;
        cout << (n + 1) / 2 << endl;
        for (int i = 0; i < (n + 1) / 2; i++)
        {
            int bPos = (i * 3) + 1;
            int nPos = 3 * (n - i);
            assert(bPos < nPos);
            cout << bPos << ' ' << nPos << endl;
        }
    }
    return 0;
}