// Official: Correct
#include <iostream>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long tests, n, x, sum;
    cin >> tests;
    while (tests--)
    {
        cin >> n;
        sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            sum += x;
        }
        cout << abs(sum) << endl;
    }
    return 0;
}