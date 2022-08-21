// 7:48 - 8:10
#include <iostream>
using namespace std;

int main(void)
{
    int tests, n, x;
    cin >> tests;
    while (tests--)
    {
        bool type5 = false;
        bool typeElse = false;
        cin >> n;
        int *arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] % 5 == 0)
                type5 = true;
            else
                typeElse = true;
            if (arr[i] % 10 != 0 && 8 % (arr[i] % 10) != 0)
                arr[i] += 10;
            arr[i] /= 10;
        }
        bool ans = true;
        if (typeElse && type5)
            ans = false;
        else if (type5)
            for (int i = 0; i < n; i++)
                ans = ans && (arr[i] == arr[0]);
        else
            for (int i = 0; i < n; i++)
                ans = ans && (arr[i] % 2 == arr[0] % 2);
        cout << (ans ? "YES" : "NO") << endl;
    }
    return 0;
}