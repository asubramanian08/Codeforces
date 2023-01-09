// Official: Correct
#include <iostream>
#include <map>
using namespace std;
#define MOD 998244353
#define BASE 100000

int main(void)
{
    ios_base::sync_with_stdio(false);
    long long n, arr[310];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int curr = 0;
    long long DP[2][2 * BASE] = {0};
    DP[curr][arr[1] + BASE] = 1;
    for (int i = 1; i <= n - 2; i++)
    {
        for (long long j = 0; j < 2 * BASE; j++)
            DP[1 - curr][j] = 0;
        for (long long j = 0; j < 2 * BASE; j++)
            if (DP[curr][j] != 0)
            {
                DP[1 - curr][arr[i + 1] + (j - BASE) + BASE] += DP[curr][j];
                DP[1 - curr][arr[i + 1] + (j - BASE) + BASE] %= MOD;
                if (j - BASE != 0)
                {
                    DP[1 - curr][arr[i + 1] - (j - BASE) + BASE] += DP[curr][j];
                    DP[1 - curr][arr[i + 1] - (j - BASE) + BASE] %= MOD;
                }
            }
        curr = 1 - curr;
    }
    long long ans = 0;
    for (long long j = 0; j < 2 * BASE; j++)
        ans = (ans + DP[curr][j]) % MOD;
    cout << ans;
    return 0;
}