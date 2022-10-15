// Official: Correct
#include <iostream>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tests, n, k;
    cin >> tests;
    while (tests--)
    {
        cin >> n >> k;
        int oneCt = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            oneCt += x;
        }
        cout << ((oneCt > 0 && n >= k) ? "YES" : "NO") << endl;
    }
    return 0;
}