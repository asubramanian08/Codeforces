//Official: correct
#include <iostream>
using namespace std;

#define MOD 1000000007

int main(void)
{
    int levels;
    cin >> levels;
    long long *colorings = new long long[levels];
    colorings[0] = 2;
    for (int i = 1; i < levels; i++)
        colorings[i] = (colorings[i - 1] * colorings[i - 1] * 8) % MOD;
    cout << (colorings[levels - 1] * 3 % MOD) << endl;
    return 0;
}