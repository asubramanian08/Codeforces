// 7:11 - 7:41
#include <iostream>
#include <string>
using namespace std;

#define MAX_LEN 120
#define INF 1000000000

int main(void)
{
    int tests, n;
    cin >> tests;
    int minTill[MAX_LEN], stringUsed[MAX_LEN], from[MAX_LEN];
    while (tests--)
    {
        string str;
        cin >> str >> n;
        string *s = new string[n];
        for (int i = 0; i < n; i++)
            cin >> s[i];
        for (int i = 0; i < MAX_LEN; i++)
            minTill[i] = INF;
        minTill[0] = 0;
        auto matches = [&](int i, int j)
        {
            for (int k = 0; k < s[j].size(); k++)
                if (k + i >= str.size() || str[i + k] != s[j][k])
                    return false;
            return true;
        };
        for (int i = 0; i < MAX_LEN; i++)
        {
            if (minTill[i] == INF)
                break;
            for (int j = 0; j < n; j++)
                if (matches(i, j))
                    for (int k = 0; k < s[j].size(); k++)
                        if (minTill[i + k + 1] > minTill[i] + 1)
                        {
                            minTill[i + k + 1] = minTill[i] + 1;
                            stringUsed[i + k + 1] = j;
                            from[i + k + 1] = i;
                        }
        }
        cout << (minTill[str.size()] != INF ? minTill[str.size()] : -1) << endl;
        if (minTill[str.size()] == INF)
            continue;
        for (int at = str.size(); at != 0; at = from[at])
            cout << (stringUsed[at] + 1) << ' ' << (from[at] + 1) << endl;
    }
    return 0;
}