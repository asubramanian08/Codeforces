// Official: Correct
#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int tests, a1, a2, b1, b2;
    cin >> tests;
    for (int test = 0; test < tests; test++)
    {
        cin >> a1 >> a2 >> b1 >> b2;
        int sum = a1 + a2 + b1 + b2;
        cout << (sum == 1 ? 1 : sum / 2) << endl;
    }
    return 0;
}