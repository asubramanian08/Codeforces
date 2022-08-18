// Official: Correct
#include <iostream>
using namespace std;

int main(void)
{
    int tests, n, a;
    cin >> tests;
    while (tests--)
    {
        cin >> n;
        int max1 = 0, max2 = 0;
        int min1 = 1'000'000'000, min2 = 1'000'000'000;
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            if (a > max1)
            {
                max2 = max1;
                max1 = a;
            }
            else
                max2 = max(max2, a);
            if (a < min1)
            {
                min2 = min1;
                min1 = a;
            }
            else
                min2 = min(min2, a);
        }
        cout << (max1 + max2 - (min1 + min2)) << endl;
    }
    return 0;
}