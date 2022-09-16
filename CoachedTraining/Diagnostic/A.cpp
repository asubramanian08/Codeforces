#include <iostream>
using namespace std;

int main(void)
{
    long long n, ans = 0, pow = 1;
    cin >> n;
    long long pow4_Nmin3, pow4_Nmin2;
    for (int i = 1; i <= n - 3; i++)
        pow *= 4;
    pow4_Nmin3 = pow;
    pow4_Nmin2 = pow * 4;
    ans = (pow4_Nmin3 * 3 * 3) * (n - 3);
    ans += 2 * (pow4_Nmin2 * 3);
    cout << ans << endl;
    return 0;
}