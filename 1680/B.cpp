// 5:10 - 5:21
#include <iostream>
using namespace std;

int main(void)
{
    int tests, n, m;
    char ch;
    cin >> tests;
    for (int test = 0; test < tests; test++)
    {
        cin >> n >> m;
        int upper = -1, left = m;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                cin >> ch;
                if (ch == 'R' && upper == -1)
                    upper = j;
                if (ch == 'R')
                    left = min(left, j);
            }
        cout << (upper == left ? "YES" : "NO") << endl;
    }
    return 0;
}