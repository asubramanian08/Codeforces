// TLE: Test 33
#include <iostream>
#include <string>
using namespace std;

int n, m, usedBy[100010] = {0}, x;

int sqrt(int x)
{
    int lo = 1, hi = x;
    while (hi - lo > 1)
        if (int mid = (hi + lo) / 2; mid * mid >= x)
            hi = mid;
        else
            lo = mid;
    return hi;
}

string change(bool add, int x, int sq)
{
    if ((add && usedBy[x] == x) || (!add && usedBy[x] != x))
        return "Already "s + (add ? "on" : "off");
    if (add)
    {
        for (int j = 2; j <= sq; j++)
            if (x % j == 0)
            {
                int k = x / j;
                if (usedBy[j] != 0)
                    return "Conflict with "s + to_string(usedBy[j]);
                if (usedBy[k] != 0 && k != 1)
                    return "Conflict with "s + to_string(usedBy[k]);
            }
        if (usedBy[x] != 0)
            return "Conflict with "s + to_string(usedBy[x]);
    }
    usedBy[x] = (add ? x : 0);
    for (int j = 2; j <= sq; j++)
        if (x % j == 0)
        {
            int k = x / j;
            usedBy[j] = (add ? x : 0);
            if (k != 1)
                usedBy[k] = (add ? x : 0);
        }
    return "Success";
}

int main(void)
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        char ch;
        cin >> ch >> x;
        cout << change(ch == '+', x, sqrt(x)) << endl;
    }
    return 0;
}