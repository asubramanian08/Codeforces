// 7:00 - 7:32
#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    int tests, n;
    cin >> tests;
    for (int test = 0; test < tests; test++)
    {
        cin >> n;
        long long *a = new long long[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        long long bias = 0, total = 0, left = a[0];
        for (int i = 1; i < n; i++)
        {
            a[i] -= bias;
            if (left < a[i])
            {
                bias += a[i] - left;
                total += a[i] - left;
            }
            else
            {
                total += left - a[i];
                left = a[i];
            }
        }
        total += abs(left);
        cout << total << endl;
    }
    return 0;
}