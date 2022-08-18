// Official: Correct
#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int tests, n, m;
    cin >> tests;
    while (tests--)
    {
        cin >> n >> m;
        string *grid = new string[n];
        for (int i = 0; i < n; i++)
            cin >> grid[i];
        auto getVal = [&](int r, int c)
        {
            if (r < 0 || r >= n || c < 0 || c >= m)
                return 1;
            return grid[r][c] - '0';
        };
        int total1 = 0, minL = 3;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                int up = getVal(i - 1, j);
                int down = getVal(i + 1, j);
                int left = getVal(i, j - 1);
                int right = getVal(i, j + 1);
                int ans = min(min(up, down) + right, min(up, down) + left);
                minL = min(minL, ans + grid[i][j] - '0');
                total1 += grid[i][j] - '0';
            }
        cout << (total1 - minL + (minL != 0)) << endl;
    }
    return 0;
}