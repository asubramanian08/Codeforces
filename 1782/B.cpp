// Official: Correct
#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    int tests, n, arr[200010], x;
    cin >> tests;
    while (tests--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        sort(arr, arr + n);
        int ans = 1 + (arr[0] != 0);
        for (int i = 0; i < n - 1; i++)
            if (i >= arr[i] && i + 1 < arr[i + 1])
                ans++;
        cout << ans << endl;
    }
    return 0;
}