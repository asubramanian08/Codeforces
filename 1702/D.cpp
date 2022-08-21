// 10:22 - 10:31
#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int tests, p, occurrence[26];
    string str;
    cin >> tests;
    for (int test = 0; test < tests; test++)
    {
        cin >> str >> p;
        int totalP = 0;
        for (int i = 0; i < 26; i++)
            occurrence[i] = 0;
        for (char ch : str)
        {
            int pos = ch - 'a';
            occurrence[pos]++;
            totalP += pos + 1;
        }
        for (int i = 25; i >= 0 && totalP > p; i--)
        {
            int remove = min(occurrence[i], (totalP - p + i) / (i + 1));
            occurrence[i] -= remove;
            totalP -= remove * (i + 1);
        }
        for (int i = 0; i < str.size(); i++)
            if (occurrence[str[i] - 'a'] > 0)
            {
                cout << str[i];
                occurrence[str[i] - 'a']--;
            }
        cout << endl;
    }
    return 0;
}