#include <iostream>
#include <set>
using namespace std;

int main(void)
{
    long long n, x;
    char ch;
    cin >> n;
    multiset<long long> A = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> ch >> x;
        if (ch == '+')
            A.insert(x);
        else if (ch == '-')
            A.erase(A.find(x));
        else
        {
            long long curr = 0, seen = 0;
            for (int j = 29; j >= 0; j--)
            {
                curr |= (~x & (1 << j));
                seen |= (1 << j);
                auto pos = A.lower_bound(curr);
                if (pos == A.end() || (*pos & seen) != curr)
                {
                    if (curr & (1 << j))
                        curr = curr & ~(1 << j);
                    else
                        curr |= (1 << j);
                }
            }
            cout << (x ^ curr) << endl;
        }
    }
    return 0;
}