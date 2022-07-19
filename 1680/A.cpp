// 5:07 - 5:10
#include <iostream>
using namespace std;

int main(void)
{
    int tests, l1, l2, r1, r2;
    cin >> tests;
    for (int test = 0; test < tests; test++)
    {
        cin >> l1 >> r1 >> l2 >> r2;
        int ans = max(l1, l2);
        if (l2 > r1 || l1 > r2)
            ans = l1 + l2;
        cout << ans << endl;
    }
    return 0;
}