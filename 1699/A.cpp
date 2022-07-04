// Official: Correct
#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int tests, n;
    cin >> tests;
    for (int test = 0; test < tests; test++)
    {
        cin >> n;
        cout << (n % 2 ? "-1" : to_string(n / 2) + " 0 0") << endl;
    }
    return 0;
}