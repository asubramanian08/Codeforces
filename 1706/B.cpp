// Official: Correct
#include <iostream>
using namespace std;

int main(void)
{
    int tests, n, c;
    cin >> tests;
    for (int test = 0; test < tests; test++)
    {
        cin >> n;
        int *maxL = new int[n];
        int *curr = new int[n];
        int *last = new int[n];
        for (int i = 0; i < n; i++)
        {
            maxL[i] = curr[i] = 0;
            last[i] = -1;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> c;
            c--;
            if (last[c] == -1 || (i - last[c]) % 2 == 1)
                curr[c]++, last[c] = i;
            maxL[c] = max(maxL[c], curr[c]);
        }
        for (int i = 0; i < n; i++)
            cout << maxL[i] << ' ';
        cout << endl;
    }
    return 0;
}