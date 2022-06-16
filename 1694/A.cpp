// Official: Correct
#include <iostream>
using namespace std;

int main(void)
{
    int tests, a, b;
    cin >> tests;
    for (int test = 0; test < tests; test++)
    {
        cin >> a >> b;
        while (a > 0 && b > 0)
        {
            cout << "01";
            a--, b--;
        }
        for (int i = 0; i < a; i++)
            cout << '0';
        for (int i = 0; i < b; i++)
            cout << '1';
        cout << endl;
    }
    return 0;
}