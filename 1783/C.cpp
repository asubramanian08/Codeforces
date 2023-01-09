// Official: Correct
#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    int tests, n, m, arr[500010], sorted[500010], ps[500010], cost;
    cin >> tests;
    while (tests--)
    {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            sorted[i] = arr[i];
        }
        sort(sorted, sorted + n);
        ps[0] = sorted[0];
        for (int i = 1; i < n; i++)
            ps[i] = ps[i - 1] + sorted[i];
        for (int i = n - 1; i >= 0; i--)
        {
            // beat i + 1 opponents
            cost = ps[i];
            // beat arr[i] and i-1 opponents
            if (i < 2)
                cost = min(cost, arr[i]);
            else if (sorted[i - 2] >= arr[i])
                cost = min(cost, ps[i - 1]);
            else // arr[i] not within ps[i - 2]
                cost = min(cost, arr[i] + ps[i - 2]);
            // found a spot
            if (cost <= m)
            {
                cout << (n - i) << endl;
                break;
            }
        }
        if (cost > m)
            cout << (n + 1) << endl;
    }
    return 0;
}