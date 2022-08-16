// Official: Correct
#include <iostream>
#include <set>
using namespace std;

int main(void)
{
    int tests, n;
    cin >> tests;
    for (int test = 0; test < tests; test++)
    {
        cin >> n;
        long long *arr = new long long[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        set<long long> options;
        long long last = 0, cost = 0;
        for (int i = 0; i < n; i++)
        {
            if ((arr[i] ^ last) == 0 || options.find(arr[i] ^ last) != options.end())
            {
                options.clear();
                last = 0;
            }
            else
            {
                last ^= arr[i];
                options.insert(last);
                cost++;
            }
        }
        cout << cost << endl;
    }
    return 0;
}