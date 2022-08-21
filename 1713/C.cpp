// 9:21 - 9:51
#include <iostream>
#include <vector>
using namespace std;
#define MAX_LEN 100'010

int main(void)
{
    int squareUsed[MAX_LEN];
    for (int i = 0; i < MAX_LEN; i++)
        squareUsed[i] = -1;
    squareUsed[0] = 0;
    vector<int> squares;
    for (int i = 0; i * i < 2 * MAX_LEN; i++)
        squares.push_back(i * i);
    for (int i = 1; i < MAX_LEN; i++)
        for (int sq : squares)
        {
            int from = sq - (i - 1);
            if (from < 0 || squareUsed[from] == -1)
                continue;
            squareUsed[i] = sq;
            break;
        }

    int tests, n;
    cin >> tests;
    for (int test = 0; test < tests; test++)
    {
        cin >> n;
        if (squareUsed[n] == -1)
        {
            cout << -1 << endl;
            continue;
        }
        int *arr = new int[n];
        int currSquare = squareUsed[n], endsAt = currSquare - (n - 1);
        for (int i = n - 1; i >= 0; i--)
        {
            if (i + 1 == endsAt)
            {
                currSquare = squareUsed[i + 1];
                endsAt = currSquare - i;
            }
            arr[i] = currSquare - i;
        }
        for (int i = 0; i < n; i++)
            cout << arr[i] << ' ';
        cout << endl;
    }
    return 0;
}