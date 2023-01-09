// Official: Correct
#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    long long tests, n, arr[55];
    cin >> tests;
    while (tests--)
    {
        cin >> n;
        bool same = true;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] != arr[0])
                same = false;
        }
        if (same)
        {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        sort(arr, arr + n, greater<int>());
        if (arr[0] == arr[1])
            swap(arr[1], arr[n - 1]);
        for (int i = 0; i < n; i++)
            cout << arr[i] << ' ';
        cout << endl;
    }
    return 0;
}