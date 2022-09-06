// Official: Correct
#include <iostream>
using namespace std;

int main(void)
{
    int tests, n, largest, smallest;
    cin >> tests;
    while (tests--)
    {
        cin >> n;
        largest = 0, smallest = 1000;
        int *arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            largest = max(largest, arr[i]);
            smallest = min(smallest, arr[i]);
        }
        int ans = arr[n - 1] - arr[0];
        for (int i = 0; i < n - 1; i++)
            ans = max(ans, arr[i] - arr[i + 1]);
        ans = max(ans, largest - arr[0]);
        ans = max(ans, arr[n - 1] - smallest);
        cout << ans << endl;
    }
    return 0;
}