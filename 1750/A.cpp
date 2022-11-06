// Official: Correct
#include <iostream>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    long long tests, n, first, smallest, x;
    cin >> tests;
    while (tests--)
    {
        cin >> n >> first;
        smallest = first;
        for (int i = 1; i < n; i++)
        {
            cin >> x;
            smallest = min(smallest, x);
        }
        cout << (first == smallest ? "YES" : "NO") << endl;
    }
    return 0;
}