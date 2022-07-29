// 6:19-6:30
#include <iostream>
using namespace std;
#define MAX_LOG 35

int main(void)
{
    long long tests, n, k;
    cin >> tests;
    for (int test = 0; test < tests; test++)
    {
        cin >> n >> k;
        long long *a = new long long[n];
        long long sum = 0, totalK = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
            totalK += k;
        }
        long long ans = sum - totalK;
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; (j < MAX_LOG) && (i + j < n); j++)
                sum -= (a[i + j]) - (a[i + j] /= 2);
            ans = max(ans, sum - (totalK -= k));
        }
        cout << ans << endl;
    }
    return 0;
}