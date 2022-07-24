// Official: Correct
#include <iostream>
using namespace std;

int main(void)
{
    int tests, n;
    cin >> tests;
    for (int test = 0; test < tests; test++)
    {
        cin >> n;
        if (n % 2 == 0)
            for (int i = 0; i < n; i++)
                if (i % 2 == 0)
                    cout << (i + 2) << ' ';
                else
                    cout << i << ' ';
        else
        {
            cout << 1 << ' ';
            for (int i = 1; i < n; i++)
                if (i % 2 == 1)
                    cout << (i + 2) << ' ';
                else
                    cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}