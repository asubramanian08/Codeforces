// Official: Correct
#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tests, n, a[200010];
    cin >> tests;
    while (tests--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        long long ans = 0;
        int notGoodAt = 0;
        for (int i = 0; i < n; i++)
        {
            while (notGoodAt < n && a[notGoodAt] >= notGoodAt - i + 1)
                notGoodAt++;
            if (notGoodAt - i > 0)
                ans += notGoodAt - i;
        }
        cout << ans << endl;
    }
    return 0;
}