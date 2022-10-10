// Official: Correct
#include <iostream>
using namespace std;

int GCD(int num1, int num2)
{
    int temp;
    while (num2)
    {
        temp = num2;
        num2 = num1 % num2;
        num1 = temp;
    }
    return num1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tests, n, a[100010], b[100010];
    cin >> tests;
    while (tests--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        b[0] = a[0];
        b[n] = a[n - 1];
        for (int i = 1; i < n; i++)
            b[i] = a[i] * a[i - 1] / GCD(a[i], a[i - 1]);
        bool works = true;
        for (int i = 1; i <= n && works; i++)
            works = GCD(b[i], b[i - 1]) == a[i - 1];
        cout << (works ? "YES" : "NO") << endl;
    }
    return 0;
}