// Official:
#include <iostream>
using namespace std;

int main(void)
{
    int tests, len, start, x;
    cin >> tests;
    for (int test = 0; test < tests; test++)
    {
        cin >> len;
        bool works = true;
        cin >> start;
        for (int i = 1; i < len; i++)
        {
            cin >> x;
            works = works && ((x / start) * start == x);
        }
        cout << (works ? "YES" : "NO") << endl;
    }
    return 0;
}