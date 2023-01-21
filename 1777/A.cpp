// Official: Correct
#include <iostream>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    int tests, n, last, x;
    cin >> tests;
    while (tests--)
    {
        cin >> n >> last;
        int count = 0;
        for (int i = 1; i < n; i++)
        {
            cin >> x;
            if (x % 2 == last % 2)
                count++;
            last = x;
        }
        cout << count << endl;
    }
    return 0;
}