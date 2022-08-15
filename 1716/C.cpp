// 12:22 - 2:13
#include <iostream>
using namespace std;

int main(void)
{
    int tests, *grid[2], *remCost[2], m;
    cin >> tests;
    while (tests--)
    {
        cin >> m;
        grid[0] = new int[m];
        grid[1] = new int[m];
        for (int row = 0; row < 2; row++)
            for (int i = 0; i < m; i++)
            {
                cin >> grid[row][i];
                grid[row][i]++;
            }
        grid[0][0] = 0;

        remCost[0] = new int[m];
        remCost[1] = new int[m];
        int last[2] = {0, 0}, secLeft = 0, row = m % 2;
        for (int i = m - 1; i >= 0; i--)
        {
            last[row] = remCost[row][i] = max(last[row], grid[row][i] + secLeft);
            secLeft++;

            row = 1 - row;
            if (i != m - 1)
            {
                remCost[row][i] = max(last[row] + 2, grid[row][i] + secLeft);
                remCost[row][i] = max(remCost[row][i], grid[1 - row][i]);
                remCost[row][i] = max(remCost[row][i], grid[1 - row][i + 1] + 1);
            }
            else
                remCost[row][i] = max(remCost[1 - row][i], grid[row][i] + 1);
            last[row] = remCost[row][i];
            secLeft++;
        }

        int ans = remCost[0][0], curr = 0, movesLeft = 2 * m - 1;
        for (int i = 0; i < m; i++)
        {
            curr = max(curr, grid[row][i] + movesLeft);
            ans = min(ans, max(curr, remCost[1 - row][i]));
            movesLeft--;

            row = 1 - row;
            curr = max(curr, grid[row][i] + movesLeft);
            ans = min(ans, max(curr, i == m - 1 ? 0 : remCost[row][i + 1]));
            movesLeft--;
        }

        cout << ans << endl;
        delete[] grid[0];
        delete[] grid[1];
        delete[] remCost[0];
        delete[] remCost[1];
    }
    return 0;
}