// Official: Correct
#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    int tests, len;
    cin >> tests;
    for (int test = 0; test < tests; test++)
    {
        long long maxSum, currSum = 0;
        cin >> len >> maxSum;
        long long *arr = new long long[len];
        for (int i = 0; i < len; i++)
        {
            cin >> arr[i];
            currSum += arr[i];
        }
        sort(arr, arr + len);
        long long ans = currSum - maxSum, involved = 1;
        for (int i = len - 1; i > 0; i--)
        {
            involved++;
            currSum -= arr[i] - arr[0];
            long long toReduce = max(currSum - maxSum, 0ll);
            long long minReduce = (toReduce + involved - 1) / involved;
            ans = min(ans, minReduce + involved - 1);
        }
        ans = max(ans, 0ll);
        cout << ans << endl;
    }
    return 0;
}