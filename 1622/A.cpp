// Official: Correct
#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    int tests, arr[3];
    cin >> tests;
    for (int test = 0; test < tests; test++)
    {
        cin >> arr[0] >> arr[1] >> arr[2];
        sort(arr, arr + 3);
        if ((arr[2] == arr[0] + arr[1]) ||
            (arr[0] == arr[1] && arr[2] % 2 == 0) ||
            (arr[1] == arr[2] && arr[0] % 2 == 0))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}