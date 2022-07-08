// Official: Correct
#include <iostream>
#include <string>
using namespace std;
#define MAX_N 200000

int main(void)
{
    int tests, n;
    cin >> tests;
    bool used[MAX_N];
    for (int test = 0; test < tests; test++)
    {
        cin >> n;
        cout << 2 << endl;
        for (int i = 1; i <= n; i++)
            used[i] = false;
        for (int i = 1; i <= n; i++)
            if (!used[i])
                for (int j = i; j <= n; j *= 2)
                {
                    used[j] = true;
                    cout << j << ' ';
                }
        cout << endl;
    }
    return 0;
}