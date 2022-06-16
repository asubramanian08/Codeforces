// Official: Failed on test 2
#include <iostream>
using namespace std;

int main(void)
{
    int tests, len;
    cin >> tests;
    for (int test = 0; test < tests; test++)
    {
        cin >> len;
        int *a = new int[len];
        for (int i = 0; i < len; i++)
            cin >> a[i];
        // int left = 0, right;
        // for (right = len - 1; right >= 0; right--)
        //     if (a[right] != 0)
        //         break;
        // while (left < right && a[left] >= 0 && a[right] <= 0)
        // {
        //     int change = min(a[left], -a[right]);
        //     a[left] -= change;
        //     a[right] += change;
        //     while (left < len && a[left] == 0)
        //         left++;
        //     while (right >= 0 && a[right] == 0)
        //         right--;
        // }

        // int total = 0, it;
        // for (it = 0; it < len; it++)
        // {
        //     total += a[it];
        //     if (total <= 0)
        //         break;
        // }
        // bool works = total == 0;
        // while (works && (++it) < len)
        //     works = a[it] == 0;

        int pos = 0, neg = 0;
        while (pos <= neg && neg < len)
        {
            while (neg < len && a[neg] >= 0)
                neg++;
            if (neg >= len)
                break;
            int diff = min(a[pos], -a[neg]);
            a[pos] -= diff;
            a[neg] += diff;
            while (pos < len && a[pos] <= 0)
            {
                if (a[pos] < 0)
                    pos = len;
                pos++;
            }
        }
        bool works = true;
        for (int i = 0; i < len && works; i++)
            works = (a[i] == 0);
        cout << (works ? "Yes" : "No") << endl;
        delete[] a;
    }
    return 0;
}