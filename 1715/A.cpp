// Official:
#include <iostream>
using namespace std;

int main(void)
{
    int tests, n, m;
    cin >> tests;
    while (tests--)
    {
        cin >> n >> m;
        if (n == 1 && m == 1)
            cout << 0 << endl;
        else
            cout << (((n - 1) + (m - 1)) + min(n, m)) << endl;
    }
    return 0;
}