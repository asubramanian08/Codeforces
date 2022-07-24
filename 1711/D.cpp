// Official: Unattempted
#include <iostream>
using namespace std;
using pii = pair<int, int>;

int main(void)
{
    int tests, n, m;
    cin >> tests;
    for (int test = 0; test < tests; test++)
    {
        cin >> n >> m;
        pii *rain = new pii[n];
        // (position, intensity)
        for (int i = 0; i < n; i++)
            cin >> rain[i].first >> rain[i].second;

        int psLen = n + 5;
        int *ps = new int[psLen];
        for (int i = 0; i < psLen; i++)
            ps[i] = 0;
        for (int i = 0; i < n; i++)
        {
            int start = rain[i].first - (rain[i].second - 1);
            int end = rain[i].first + (rain[i].second - 1);
            ps[start] += 1;
            ps[rain[i].first + 1] -= 2;
            ps[end + 2] += 1;
        }
        for (int i = 1; i < psLen; i++)
            ps[i] += ps[i - 1];
        for (int i = 1; i < psLen; i++)
            ps[i] += ps[i - 1];

        int *
    }
    return 0;
}