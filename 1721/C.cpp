// Official: Correct
#include <iostream>
using namespace std;

int main(void)
{
    int tests, n, a[200010], b[200010];
    cin >> tests;
    while (tests--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        a[n] = 2000000000;
        int smallIdx = 0;
        for (int i = 0; i < n; i++)
        {
            while (a[i] > b[smallIdx])
                smallIdx++;
            cout << (b[smallIdx] - a[i]) << ' ';
        }
        cout << endl;
        int largeIdx = 1;
        for (int i = 0; i < n; i++)
        {
            largeIdx = max(largeIdx, i + 1);
            while (a[largeIdx] <= b[largeIdx - 1])
                largeIdx++;
            cout << (b[largeIdx - 1] - a[i]) << ' ';
        }
        cout << endl;
    }
}