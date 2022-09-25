// Official: Correct
#include <iostream>
using namespace std;

int main()
{
    int tests, n, c, x;
    int arr[101];
    cin >> tests;
    while (tests--)
    {
        cin >> n >> c;
        for (int i = 0; i <= 100; i++)
            arr[i] = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            arr[x]++;
        }
        int ans = 0;
        for (int i = 0; i <= 100; i++)
            ans += min(arr[i], c);
        cout << ans << endl;
    }
    return 0;
}