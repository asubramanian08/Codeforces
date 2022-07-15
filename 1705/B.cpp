// Official: Correct
#include <iostream>
using namespace std;

int main(void)
{
    long long tests, n, total_dust, zeros, d;
    cin >> tests;
    for (int test = 0; test < tests; test++)
    {
        cin >> n;
        total_dust = zeros = 0;
        for (int i = 0; i < n - 1; i++)
        {
            cin >> d;
            if (d == 0)
                zeros += (total_dust != 0);
            else
                total_dust += d;
        }
        cin >> d; // last one
        cout << (total_dust + zeros) << endl;
    }
    return 0;
}