// Official: Correct
#include <iostream>
using namespace std;
#define MOD 1000000007

int main(void)
{
    int tests, len;
    cin >> tests;
    for (int test = 0; test < tests; test++)
    {
        cin >> len;
        int *seq = new int[len];
        int *locOf = new int[len];
        for (int i = 0; i < len; i++)
        {
            cin >> seq[i];
            locOf[seq[i]] = i;
        }
        int l = min(locOf[0], locOf[1]),
            r = max(locOf[0], locOf[1]);
        long long ans = 1;
        for (int i = 2; i < len; i++)
        {
            if (l < locOf[i] && locOf[i] < r)
                ans = (ans * (r - l - i + 1)) % MOD;
            l = min(l, locOf[i]);
            r = max(r, locOf[i]);
        }
        cout << ans << endl;
    }
    return 0;
}