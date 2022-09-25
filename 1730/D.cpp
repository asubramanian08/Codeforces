// Official: Correct
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    int tests, n;
    cin >> tests;
    while (tests--)
    {
        cin >> n;
        string s1, s2;
        cin >> s1 >> s2;
        map<pair<char, char>, int> mp;
        for (int i = 0; i < n; i++)
        {
            char ch1 = s1[i];
            char ch2 = s2[n - i - 1];
            mp[{min(ch1, ch2), max(ch1, ch2)}]++;
        }
        int oddPairs = 0;
        bool works = true;
        for (auto it : mp)
            if ((oddPairs += it.second % 2) > n % 2 ||
                (it.first.first != it.first.second && it.second % 2))
            {
                works = false;
                break;
            }
        cout << (works ? "YES" : "NO") << endl;
    }
    return 0;
}