// Official: Correct
#include <iostream>
using namespace std;

int main(void)
{
    int tests, n, m;
    cin >> tests;
    while (tests--)
    {
        cin >> n >> m;
        if (m < n)
            cout << "NO" << endl;
        else if (n % 2 == 1)
        {
            cout << "YES" << endl;
            for (int i = 0; i < n - 1; i++)
                cout << 1 << " ";
            cout << m - (n - 1) << endl;
        }
        else if (m % 2 == 0)
        {
            cout << "YES" << endl;
            for (int i = 0; i < n - 2; i++)
                cout << 1 << " ";
            int rem = m - (n - 2);
            cout << (rem / 2) << " " << (rem / 2) << endl;
        }
        else
            cout << "NO" << endl;
    }
    return 0;
}