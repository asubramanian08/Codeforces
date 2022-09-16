#include <iostream>
using namespace std;
#define MOD 1000000007

long long a, b, n, sum, ans;
long long fact[1000010];
long long pow(long long a, long long b)
{
    if (b == 0) return 1;
    long long half_pow = pow(a, b / 2);
    long long pow_ish = (half_pow * half_pow) % MOD;
    return (pow_ish * (b % 2 ? a : 1)) % MOD;
}
long long inverse(long long p) { return pow(p, MOD - 2); }
long long choose(long long a, long long b) { return ((fact[a] * inverse(fact[b])) % MOD * inverse(fact[a - b])) % MOD; }

int main(void)
{
    cin >> a >> b >> n;

    fact[0] = 1;
    for (int i = 1; i <= n; i++)
        fact[i] = (fact[i - 1] * i) % MOD;

    ans = 0;
    for (int i = 0; i <= n; i++)
    {
        for (sum = (i * a) + (n - i) * b; sum; sum /= 10)
            if (sum % 10 != a && sum % 10 != b) break;
        if (sum == 0) ans = (ans + choose(n, i)) % MOD;
    }
    cout << ans << endl;
    return 0;
}