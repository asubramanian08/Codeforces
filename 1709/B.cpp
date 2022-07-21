// Official: Correct
#include <iostream>
#include <cassert>
using namespace std;

int main(void)
{
    int tests, n, m;
    cin >> n >> m;
    long long *arr = new long long[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    long long *fps = new long long[n];
    fps[0] = 0;
    for (int i = 1; i < n; i++)
        fps[i] = fps[i - 1] + max(arr[i - 1] - arr[i], 0LL);
    long long *bps = new long long[n];
    bps[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--)
        bps[i] = bps[i + 1] + max(arr[i + 1] - arr[i], 0LL);
    for (int i = 0; i < m; i++)
    {
        long long x, y, ans;
        cin >> x >> y;
        x--, y--;
        if (x < y)
            ans = fps[y] - fps[x];
        else
            ans = bps[y] - bps[x];
        assert(ans >= 0);
        cout << ans << endl;
    }
    return 0;
}