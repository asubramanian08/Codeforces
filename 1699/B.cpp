// Official: Correct
#include <iostream>
using namespace std;

int main(void)
{
    int tests, n, m;
    cin >> tests;
    bool copyMat[4][4] = {
        {1, 0, 0, 1},
        {0, 1, 1, 0},
        {0, 1, 1, 0},
        {1, 0, 0, 1}};
    for (int test = 0; test < tests; test++)
    {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cout << copyMat[i % 4][j % 4] << ' ';
            cout << endl;
        }
    }
    return 0;
}