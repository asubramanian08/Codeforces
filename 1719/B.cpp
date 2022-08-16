// Official: Correct
#include <iostream>
using namespace std;

int main(void)
{
    int tests, n, k;
    cin >> tests;
    for (int test = 0; test < tests; test++)
    {
        cin >> n >> k;
        if (k % 4 == 0)
        {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        for (int i = 1; i < n; i += 2)
            if (k % 2 == 1 || (i + 1) % 4 == 0)
                cout << i << ' ' << (i + 1) << endl;
            else
                cout << (i + 1) << ' ' << i << endl;
    }
    return 0;
}