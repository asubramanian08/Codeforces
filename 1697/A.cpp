// Official: Correct
#include <iostream>
using namespace std;

int main(void)
{
    int tests, benchCt, init;
    cin >> tests;
    for (int test = 0; test < tests; test++)
    {
        cin >> benchCt >> init;
        int reqEnergy = 0, en;
        for (int i = 0; i < benchCt; i++)
        {
            cin >> en;
            reqEnergy += en;
        }
        cout << max(reqEnergy - init, 0) << endl;
    }
    return 0;
}