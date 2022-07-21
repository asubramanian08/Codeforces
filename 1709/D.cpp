// Official: Time limit test 11
#include <iostream>
#include <cmath>
using namespace std;

long long **st, mLog, *pow2;

inline long long maxRange(long long left, long long right)
{
    long long mr = 0;
    for (long long j = mLog; j >= 0; j--)
        if (left + pow2[j] <= right)
        {
            mr = max(mr, st[left][j]);
            left = left + pow2[j];
        }
    return mr;
}

int main(void)
{
    long long n, m;
    cin >> n >> m;
    long long *a = new long long[m];
    for (long long i = 0; i < m; i++)
        cin >> a[i];

    st = new long long *[m];
    // st[i][l] = max(a[i], a[i+1], ... a[i + 2^l])
    mLog = log2(m) + 1;
    pow2 = new long long[mLog + 1];
    pow2[0] = 1;
    for (int i = 1; i <= mLog; i++)
        pow2[i] = pow2[i - 1] << 1;
    for (long long i = 0; i < m; i++)
    {
        st[i] = new long long[mLog];
        st[i][0] = a[i];
    }
    for (long long j = 1; j < mLog; j++)
        for (long long i = 0; i + pow2[j] <= m; i++)
            st[i][j] = max(st[i][j - 1], st[i + pow2[j - 1]][j - 1]);
    mLog = mLog - 1;

    long long q, x1, x2, y1, y2, k;
    cin >> q;
    for (long long i = 0; i < q; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2 >> k;
        y1--, y2--;
        if (y1 > y2)
        {
            swap(x1, x2);
            swap(y1, y2);
        }
        bool works = true;
        if (abs(x1 - x2) % k != 0)
            works = false;
        if (abs(y1 - y2) % k != 0)
            works = false;
        if (works)
        {
            long long largestHurdle = maxRange(y1, y2);
            if ((((n - x1) / k) * k) + x1 <= largestHurdle)
                works = false;
        }
        cout << (works ? "YES" : "NO") << endl;
    }
    return 0;
}