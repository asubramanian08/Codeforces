#include <iostream>
using namespace std;

int main(void)
{
    long long n, m;
    cin >> n >> m;
    long long *arr = new long long[n];
    for (long long i = 0; i < n; i++)
        cin >> arr[i];
    long long ans = n * (n + 1) / 2;
    for (long long i = 1; i < n; i++)
        if (arr[i] != arr[i - 1])
            ans += i * (n - i);
    while (m--)
    {
        long long i, x;
        cin >> i >> x;
        i--;
        if (i != 0 && arr[i] != arr[i - 1])
            ans -= i * (n - i);
        if (i != 0 && x != arr[i - 1])
            ans += i * (n - i);
        if (i != n - 1 && arr[i] != arr[i + 1])
            ans -= (i + 1) * (n - i - 1);
        if (i != n - 1 && x != arr[i + 1])
            ans += (i + 1) * (n - i - 1);
        arr[i] = x;
        cout << ans << endl;
    }
    return 0;
}