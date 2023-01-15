// Official: Correct
#include <iostream>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    int tests, w, d, h, a, b, f, g;
    cin >> tests;
    while (tests--)
    {
        cin >> w >> d >> h;
        cin >> a >> b >> f >> g;
        int ans1 = abs(a - f) + min(b + g, d - b + d - g) + h;
        int ans2 = abs(b - g) + min(a + f, w - a + w - f) + h;
        cout << min(ans1, ans2) << endl;
    }
    return 0;
}