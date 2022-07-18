// Official: Failed on test 2
#include <iostream>
using namespace std;

int minimize(int *h, int n)
{
    int total = 0;
    for (int i = 1; i < n - 1; i += 2)
    {
        if (max(h[i - 1], h[i + 1]) >= h[i])
            total += max(h[i - 1], h[i + 1]) - h[i] + 1;
    }
    return total;
}

int min2(int *h, int n, int total)
{
    int curr = total, minC = total;
    for (int i = n - 2; i > 0; i -= 2)
    {
        if (max(h[i - 1], h[i + 1]) >= h[i])
            curr += max(h[i - 1], h[i + 1]) - h[i] + 1;
        if (max(h[i - 2], h[i]) >= h[i - 1])
            curr -= max(h[i - 2], h[i]) - h[i - 1] + 1;
        minC = min(minC, curr);
    }
    return minC;
}

int main(void)
{
    int tests, n;
    cin >> tests;
    for (int test = 0; test < tests; test++)
    {
        cin >> n;
        int *h = new int[n];
        for (int i = 0; i < n; i++)
            cin >> h[i];
        int ans = minimize(h, n);
        if (n % 2 == 0)
            ans = min2(h, n, ans);
        cout << ans << endl;
    }
    return 0;
}