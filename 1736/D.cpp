// 3:02 - 3:25
#include <iostream>
#include <vector>
#include <string>
using namespace std;
// #define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tests, n;
    string str;
    cin >> tests;
    vector<int> b;
    while (tests--)
    {
        cin >> n >> str;
        bool prev = 0;
        b.clear();
        for (int i = 0; i < 2 * n; i += 2)
        {
            if (str[i] == str[i + 1])
                continue;
            prev = !prev;
            if (str[i] == prev + '0')
                b.push_back(i + 1);
            else
                b.push_back(i + 2);
        }
        if (b.size() % 2)
        {
            cout << -1 << endl;
            continue;
        }
        cout << b.size();
        for (int i = 0; i < b.size(); i++)
            cout << ' ' << b[i];
        cout << endl;
        for (int i = 0; i < n; i++)
            cout << (i * 2 + 1) << ' ';
        cout << endl;
    }
    return 0;
}