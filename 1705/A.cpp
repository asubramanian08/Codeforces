// Official: Correct
#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    int tests, n, x;
    cin >> tests;
    for (int test = 0; test < tests; test++)
    {
        cin >> n >> x;
        int *h = new int[2 * n];
        for (int i = 0; i < 2 * n; i++)
            cin >> h[i];
        sort(h, h + 2 * n);
        bool works = true;
        for (int i = 0; i < n && works; i++)
            works = (h[i + n] >= h[i] + x);
        cout << (works ? "YES" : "NO") << endl;
    }
    return 0;
}