// Official: Correct
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_VAL 3005

bool rangeWorks(int minVal, int maxVal, int *a, int k, int n)
{
    for (int i = 0; i < n; i++)
    {
        int x = k;
        if (minVal != 0)
            x = min(x, a[i] / minVal);
        if (a[i] / x < minVal || a[i] / x > maxVal)
            return false;
    }
    return true;
}

int main(void)
{
    int tests, maxMin, minMax, n, k;
    cin >> tests;
    for (int test = 0; test < tests; test++)
    {
        maxMin = 0;
        minMax = MAX_VAL;
        cin >> n >> k;
        int *a = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            int currMin = a[i] / k;
            int currMax = a[i] / 1;
            maxMin = max(maxMin, currMin);
            minMax = min(minMax, currMax);
        }
        int ans = MAX_VAL;
        for (int currMin = 0; currMin <= minMax; currMin++)
        {
            int lo = currMin - 2, hi = MAX_VAL + 1;
            while (hi - lo > 1)
                if (int mid = (hi + lo) / 2; rangeWorks(currMin, mid, a, k, n))
                    hi = mid;
                else
                    lo = mid;
            ans = min(ans, hi - currMin);
        }
        cout << ans << endl;
    }
    return 0;
}