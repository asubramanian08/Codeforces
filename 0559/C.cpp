// 8:23 - 9:32
#include <iostream>
#include <algorithm>
using namespace std;
using pii = pair<long long, long long>;
#define MOD 1000000007

long long fact[300010];
long long infact[300010];
long long pow(long long a, long long b)
{
    if (b == 0)
        return 1;
    long long half_pow = pow(a, b / 2);
    long long pow_ish = (half_pow * half_pow) % MOD;
    return (pow_ish * (b % 2 ? a : 1)) % MOD;
}
long long inverse(long long p) { return pow(p, MOD - 2); }
long long paths(long long l, long long w) { return ((fact[l + w] * infact[l]) % MOD * infact[w]) % MOD; }

int main(void)
{
    fact[0] = 1;
    for (long long i = 1; i < 300010; i++)
        fact[i] = (fact[i - 1] * i) % MOD;
    for (long long i = 0; i < 300010; i++)
        infact[i] = inverse(fact[i]);
    long long n, m, b;
    cin >> n >> m >> b;
    pii black[2010];
    for (int i = 0; i < b; i++)
        cin >> black[i].first >> black[i].second;
    black[b++] = {n, m};
    sort(black, black + b);
    long long waysTo[2010];
    for (int i = 0; i < b; i++)
    {
        waysTo[i] = paths(black[i].first - 1, black[i].second - 1);
        for (int j = 0; j < i; j++)
            if (black[i].first >= black[j].first && black[i].second >= black[j].second)
                waysTo[i] = (waysTo[i] + MOD - waysTo[j] * paths(black[i].first - black[j].first, black[i].second - black[j].second) % MOD) % MOD;
    }
    cout << waysTo[b - 1] << endl;
}