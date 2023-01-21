// Official: Correct
#include <iostream>
using namespace std;
#define MOD 1000000007

int main(void)
{
    ios_base::sync_with_stdio(false);
    long long tests, n;
    cin >> tests;
    while (tests--)
    {
        cin >> n;
        long long pairs = (n * (n - 1) / 2) % MOD;
        long long permutations = 1; // n!
        for (long long i = 1; i <= n; i++)
            permutations = (permutations * i) % MOD;
        long long ans = (2 * pairs * permutations) % MOD;
        cout << ans << endl;
    }
    return 0;
}