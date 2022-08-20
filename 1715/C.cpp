// Official: Wrong on test 2
#include <iostream>
using namespace std;

int main(void)
{
    int n, m, ele, x;
    cin >> n >> m;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    long long ans = n * (n + 1) / 2;
    for (int i = 1; i < n; i++)
        if (arr[i] != arr[i - 1])
            ans += i * (n - i);
    auto equalize = [&](int i)
    {
        if (i == n || i == 0)
            return;
        long long cost = i * (n - i);
        if (arr[i] != arr[i - 1])
            ans -= cost;
    };
    auto update = [&](int i)
    {
        if (i == n || i == 0)
            return;
        long long cost = i * (n - i);
        if (arr[i] != arr[i - 1])
            ans += cost;
    };
    for (int i = 0; i < m; i++)
    {
        cin >> ele >> x;
        ele--;
        if (arr[ele] != x)
        {
            equalize(ele), equalize(ele + 1);
            arr[ele] = x;
            update(ele), update(ele + 1);
        }
        cout << ans << endl;
    }
    return 0;
}