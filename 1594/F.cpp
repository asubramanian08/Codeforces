//Official: incorrect
//After looking at solution
#include <iostream>
using namespace std;

int main(void)
{
    long long numTests, animals, pens, consecutive;
    cin >> numTests;
    for (int i = 0; i < numTests; i++)
    {
        cin >> animals >> pens >> consecutive;
        if (animals == consecutive || animals - pens < pens / consecutive * consecutive)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}