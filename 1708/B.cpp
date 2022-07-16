// Official: Correct
#include <iostream>
using namespace std;

int main(void)
{
    int tests, n, l, r;
    cin >> tests;
    for (int test = 0; test < tests; test++)
    {
        cin >> n >> l >> r;
        int *arr = new int[n];
        bool works = true;
        for (int i = 1; i <= n && works; i++)
        {
            arr[i - 1] = (r / i) * i;
            works = (arr[i - 1] >= l && arr[i - 1] <= r);
        }
        cout << (works ? "YES" : "NO") << endl;
        if (works)
        {
            for (int i = 0; i < n; i++)
                cout << arr[i] << ' ';
            cout << endl;
        }
    }
    return 0;
}