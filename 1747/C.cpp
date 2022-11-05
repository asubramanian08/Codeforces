// Official: Correct
#include <iostream>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long tests, n, arr[100010];
    cin >> tests;
    while (tests--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        long long smallest = arr[1];
        for (int i = 2; i < n; i++)
            smallest = min(smallest, arr[i]);
        if (arr[0] > smallest)
            cout << "Alice" << endl;
        else
            cout << "Bob" << endl;
    }
    return 0;
}