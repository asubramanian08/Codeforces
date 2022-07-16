// Official: Unattempted
#include <iostream>
using namespace std;

int main(void)
{
    int tests, n, x;
    cin >> tests;
    for (int test = 0; test < tests; test++)
    {
        cin >> n;
        int *choose = new int[n];
        choose[0] = 1;
        for (int i = 1; i < n; i++)
            choose[i] = choose[i - 1] * (n - i) / i;
        int total = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            int c = choose[i] * x;
            total += c * (i % 2 ? -1 : 1);
        }
        cout << total << endl;
    }
    return 0;
}