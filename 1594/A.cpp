// Official: Unattempted
// After looking at solution
#include <iostream>
using namespace std;

int main(void)
{
    int tests;
    cin >> tests;
    for (int i = 0; i < tests; i++)
    {
        long long n;
        cin >> n;
        cout << (1 - n) << ' ' << n << endl;
    }
    return 0;
}