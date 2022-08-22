// 11:38 - 11:52
#include <iostream>
#include <set>
using namespace std;

int main(void)
{
    int tests, n, x;
    cin >> tests;
    for (int test = 0; test < tests; test++)
    {
        cin >> n;
        multiset<int> s;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            while (x % 2 == 0)
                x = x >> 1;
            s.insert(x);
        }
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            while (x != 0 && s.find(x) == s.end())
                x = x >> 1;
            if (x != 0)
                s.erase(s.find(x));
        }
        cout << (s.empty() ? "YES" : "NO") << endl;
    }
    return 0;
}