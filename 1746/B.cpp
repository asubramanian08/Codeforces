// Official: Correct
#include <iostream>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tests, n, a[100010];
    cin >> tests;
    while (tests--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int right0 = 0, currCost = 0;
        for (int i = 0; i < n; i++)
            if (a[i] == 0)
                right0++;
        int ans = right0;
        for (int i = 0; i < n; i++)
        {
            right0 = max(right0 - 1, 0);
            currCost += a[i];
            ans = min(ans, currCost + right0);
        }
        cout << ans << endl;
    }
    return 0;
}