// Official: Unfinished (Unattempted)
#include <iostream>
#include <set>
#include <vector>
using namespace std;

#define MAX_COL 500005

bool grid[3][MAX_COL];
int groups[3][MAX_COL] = {0};
int x[] = {0, 1, 0, -1};
int y[] = {1, 0, -1, 0};
vector<int> starts;
vector<int> endings;
void floodfill(int r, int c, int g)
{
    if (!grid[r][c] || groups[r][c] == g)
        return;
    groups[r][c] = g;
    starts[g] = min(starts[g], r);
    endings[g] = max(endings[g], c);
    for (int i = 0; i < 4; i++)
        floodfill(r + x[i], c + y[i], g);
}

int main(void)
{
    int colCt, queries;
    cin >> colCt >> queries;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < colCt; j++)
            cin >> grid[i][j];
    int groupCt = 0;
    for (int i = 0; i < colCt; i++)
        for (int j = 0; j < 3; j++)
            if (groups[i][j] == 0)
            {
                starts.push_back(23234324);
                ends.push_back(0);
                floodfill(j, i, ++groupCt);
            }
    set<int> connections;
    for (int i = 0; i < colCt; i++)
        if (grid[0][i] && grid[1][i] && grid[2][i])
            connections.insert(i);
    for (int i = 0; i < queries; i++)
    {
    }
    return 0;
}