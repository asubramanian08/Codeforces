// Official: Correct
#include <iostream>
using namespace std;

int tests, n, m, k;
long long *a;

bool isVert()
{
    long long colsCovered = 0;
    bool setBit = false;
    for (int i = 0; i < k; i++)
    {
        if (a[i] >= 2 * n)
            colsCovered += a[i] / n;
        if (a[i] >= 3 * n)
            setBit = true;
    }
    if (setBit == false && m % 2 == 1)
        return false;
    return colsCovered >= m;
}
bool isHorz()
{
    long long rowsCovered = 0;
    bool setBit = false;
    for (int i = 0; i < k; i++)
    {
        if (a[i] >= 2 * m)
            rowsCovered += a[i] / m;
        if (a[i] >= 3 * m)
            setBit = true;
    }
    if (setBit == false && n % 2 == 1)
        return false;
    return rowsCovered >= n;
}

int main(void)
{
    cin >> tests;
    for (int test = 0; test < tests; test++)
    {
        cin >> n >> m >> k;
        a = new long long[k];
        for (int i = 0; i < k; i++)
            cin >> a[i];
        cout << (isVert() || isHorz() ? "Yes" : "No") << endl;
    }
    return 0;
}