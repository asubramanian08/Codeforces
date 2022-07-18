// Official: Correct
#include <iostream>
using namespace std;

int main(void)
{
    int tests, n, m, a;
    cin >> tests;
    for (int test = 0; test < tests; test++)
    {
        cin >> n >> m;
        bool *b = new bool[m];
        for (int i = 0; i < m; i++)
            b[i] = false;
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            a = a - 1;
            int a2 = m - (a + 1);
            if (b[min(a, a2)])
                b[max(a, a2)] = true;
            else
                b[min(a, a2)] = true;
        }
        for (int i = 0; i < m; i++)
            cout << (b[i] ? "A" : "B");
        cout << endl;
    }
    return 0;
}