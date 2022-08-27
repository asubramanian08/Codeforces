// Official: Correct
#include <iostream>
using namespace std;

int main(void)
{
    int tests, n, m, sx, sy, d;
    cin >> tests;
    while (tests--)
    {
        cin >> n >> m >> sx >> sy >> d;
        sx--, sy--;
        // int xDist = max(sx, n - sx - 1);
        // int yDist = max(sy, m - sy - 1);
        if ((sx > d && m - sy - 1 > d) ||
            (n - sx - 1 > d && sy > d))
            cout << (n - 1 + m - 1) << endl;
        else
            cout << -1 << endl;
    }
}