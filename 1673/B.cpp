// Official: Correct
#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int tests;
    cin >> tests;
    for (int test = 0; test < tests; test++)
    {
        int lastOccurrence[26] = {0};
        for (int i = 0; i < 26; i++)
            lastOccurrence[i] = -1;
        string str;
        cin >> str;
        for (char ch : str)
            lastOccurrence[ch - 'a'] = 0;
        int lastestLast = 0;
        bool works = true;
        for (int i = 0; i < str.length(); i++)
        {
            if (lastOccurrence[str[i] - 'a'] != lastestLast)
                works = false;
            lastOccurrence[str[i] - 'a'] = i + 1;
            lastestLast = str.length() + 100;
            for (int j = 0; j < 26; j++)
                if (lastOccurrence[j] != -1)
                    lastestLast = min(lastestLast, lastOccurrence[j]);
        }
        cout << (works ? "YES" : "NO") << endl;
    }
    return 0;
}