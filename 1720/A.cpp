// Official: Correct
#include <iostream>
using namespace std;

int main(void)
{
    long long tests, a, b, c, d;
    cin >> tests;
    while (tests--)
    {
        cin >> a >> b >> c >> d;
        long long but1 = a * d, but2 = b * c;
        if (but1 == but2)
            cout << 0 << endl;
        else if (but1 == 0 || but2 == 0)
            cout << 1 << endl;
        else if (but1 % but2 == 0 || but2 % but1 == 0)
            cout << 1 << endl;
        else
            cout << 2 << endl;
    }
    return 0;
}