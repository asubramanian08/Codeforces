// Official: Failed on test 2
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n, arr[200010], ps[200010], q, zeros[200010], prev[200010];
    cin >> n >> q;
    ps[0] = zeros[0] = 0;
    map<pair<int, int>, int> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        ps[i] = ps[i - 1] ^ arr[i];
        zeros[i] = zeros[i - 1] + (arr[i] == 0);
        prev[i] = m.count({(i + 1) % 2, ps[i]}) ? m[{(i + 1) % 2, ps[i]}] : -1;
        m[{i % 2, ps[i]}] = i;
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        if ((ps[r] ^ ps[l - 1]) != 0)
            cout << -1 << endl;
        else if (zeros[r] - zeros[l - 1] == r - (l - 1))
            cout << 0 << endl;
        else if ((r - l + 1) % 2 == 1 || arr[l] == 0 || arr[r] == 0)
            cout << 1 << endl;
        else if (prev[r] != -1 && prev[r] > l)
            cout << 2 << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}