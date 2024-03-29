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
    long long n, arr[200010], ps[200010], q, zeros[200010];
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    ps[0] = 0;
    for (int i = 1; i <= n; i++)
        ps[i] = ps[i - 1] ^ arr[i];
    map<pair<int, int>, vector<int>> m;
    for (int i = 0; i <= n; i++)
        m[{i % 2, ps[i]}].push_back(i);
    zeros[0] = 0;
    for (int i = 1; i <= n; i++)
        zeros[i] = zeros[i - 1] + (arr[i] == 0);
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
        else
        {
            vector<int> &v = m[{(r + 1) % 2, ps[r]}];
            auto it = upper_bound(v.begin(), v.end(), r);
            if (it != v.begin() && l < *prev(it))
                cout << 2 << endl;
            else
                cout << -1 << endl;
        }
    }
    return 0;
}