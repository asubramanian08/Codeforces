//Official: correct
#include <iostream>
#include <cmath>
using namespace std;

#define MAX_BITS 30
#define MOD 1000000007

int main(void)
{
    //read
    int tests;
    cin >> tests;
    for (int i = 0; i < tests; i++)
    {
        int n, k;
        cin >> n >> k;
        long long ans = 0, mult = 1;
        for (int i = 0; i < MAX_BITS; i++)
        {
            if (k & (1 << i))
                ans = (ans + mult) % MOD;
            mult = (mult * n) % MOD;
        }
        cout << ans << endl;
    }
    return 0;
}