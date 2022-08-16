// Official: Correct
#include <iostream>
using namespace std;

int main(void)
{
    int tests, n, m;
    cin >> tests;
    for (int test = 0; test < tests; test++)
    {
        cin >> n >> m;
        cout << ((n + m) % 2 ? "Burenka" : "Tonya") << endl;
    }
    return 0;
}