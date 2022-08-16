// 8:00 - 9:04
#include <iostream>
using namespace std;
#define SQRT 650
#define MOD 998244353

int main(void)
{
    int n, k;
    cin >> n >> k;
    int *ways = new int[n + 1];
    int *totalWays = new int[n + 1];
    for (int i = 0; i <= n; i++)
        totalWays[i] = ways[i] = 0;
    ways[0] = 1;
    int *remCt = new int[n + 1];
    for (int i = k; i < SQRT + k; i++)
    {
        for (int j = 0; j <= n; j++)
            remCt[j] = 0;
        for (int j = 0; j <= n; j++)
        {
            int temp = ways[j];
            ways[j] = remCt[j % i];
            remCt[j % i] = (remCt[j % i] + temp) % MOD;
            totalWays[j] = (totalWays[j] + ways[j]) % MOD;
        }
    }
    for (int i = 1; i <= n; i++)
        cout << totalWays[i] << ' ';
    cout << endl;
    delete[] ways;
    delete[] totalWays;
    delete[] remCt;
    return 0;
}