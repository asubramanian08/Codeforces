// Official:
#include <iostream>
#include <set>
using namespace std;

int tests, n, y;
long long a[100010];
multiset<long long> b;
long long pow2[30], ans;

void updateAns()
{
    for (int i = 0; i < n; i++)
        a[i] &= ans;
    multiset<long long> temp;
    for (long long x : b)
        temp.insert(x & ans);
    b = temp;
}

bool isError(multiset<long long> t)
{
    for (int i = 0; i < n; i++)
    {
        long long curr = 0, checked = 0;
        for (int j = 30 - 1; j >= 0; j--)
            if (ans & pow2[j])
            {
                curr |= ~a[i] & pow2[j];
                checked |= pow2[j];
                auto pos = t.lower_bound(curr);
                if (pos != t.end() && (*pos & checked) == curr)
                    continue;
                ans &= ~pow2[j];
                return true;
            }
        t.erase(t.lower_bound(curr));
    }
    return false;
}

int main(void)
{
    pow2[0] = 1;
    for (int i = 1; i < 30; i++)
        pow2[i] = pow2[i - 1] * 2;
    cin >> tests;
    while (tests--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
        {
            cin >> y;
            b.insert(y);
        }
        ans = 0;
        for (int i = 0; i < 30; i++)
        {
            int count = 0;
            for (int j = 0; j < n; j++)
                count += ((a[j] & pow2[i]) > 0);
            for (long long x : b)
                count += ((x & pow2[i]) > 0);
            if (count == n)
                ans |= pow2[i];
        }
        updateAns();

        while (isError(b))
            updateAns();

        b.clear();
        cout << ans << endl;
    }
}