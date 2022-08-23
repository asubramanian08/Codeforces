// 3:58 - NA
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

int main(void)
{
    long long fib[80];
    fib[0] = fib[1] = 1;
    for (int i = 2; i < 80; i++)
        fib[i] = fib[i - 1] + fib[i - 2];
    long long ps[80];
    partial_sum(fib, fib + 80, ps);
    long long arr[110];

    int tests, n;
    cin >> tests;
    while (tests--)
    {
        cin >> n;
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            sum += arr[i];
        }
        int pos = lower_bound(ps, ps + 80, sum) - ps;
        if (sum != ps[pos])
        {
            cout << "NO" << endl;
            continue;
        }

        bool works = true;
        int last = -1;
        for (int i = pos; i >= 0 && works; i--)
        {
            int curr = -1;
            for (int j = 0; j < n; j++)
                if ((curr == -1 || arr[j] > arr[curr]) && j != last)
                    curr = j;
            if (curr == -1 || (arr[curr] -= fib[i]) < 0)
                works = false;
            last = curr;
        }
        cout << (works ? "YES" : "NO") << endl;
    }
}