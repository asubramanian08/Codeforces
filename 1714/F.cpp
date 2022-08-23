// 1:39 - 2:34
#include <iostream>
using namespace std;

int main(void)
{
    int tests, n, d12, d23, d31;
    cin >> tests;
    while (tests--)
    {
        cin >> n >> d12 >> d23 >> d31;
        int xDoub = d23 + d31 - d12;
        if (xDoub < 0 || xDoub % 2 == 1)
        {
            cout << "NO" << endl;
            continue;
        }
        int x = xDoub / 2;
        int xPos = d31 - x;
        if (x + d12 + 1 > n || d23 != d12 - xPos + x || xPos < 0 || xPos > d12)
        {
            cout << "NO" << endl;
            continue;
        }
        int xConn = xPos + 3;
        if (xPos == 0)
            xConn = 1;
        else if (xPos == d12)
            xConn = 2;
        cout << "YES" << endl;
        int prevUsed = 1;
        int nextUse = 4;
        for (int i = 1; i < d12; i++)
            if (x == 0 && i == xPos)
            {
                cout << prevUsed << ' ' << 3 << endl;
                prevUsed = 3;
            }
            else
            {
                cout << prevUsed << ' ' << nextUse << endl;
                prevUsed = nextUse;
                nextUse++;
            }
        cout << prevUsed << ' ' << 2 << endl;
        prevUsed = xConn;
        for (int i = 1; i < x; i++)
        {
            cout << prevUsed << ' ' << nextUse << endl;
            prevUsed = nextUse;
            nextUse++;
        }
        if (x != 0)
            cout << prevUsed << ' ' << 3 << endl;
        while (nextUse <= n)
        {
            cout << 1 << ' ' << nextUse << endl;
            nextUse++;
        }
    }
}