// Official: Correct
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int tests, stock1[10], stock2[10];
    cin >> tests;
    while (tests--)
    {
        string str;
        cin >> str;
        for (int i = 0; i < 10; i++)
            stock1[i] = stock2[i] = 0;
        for (char ch : str)
            stock2[ch - '0']++;

        string ans = "";
        int idx = 0, prev = -1, next = -1;
        for (int i = 9; i >= 0; i--)
            if (stock2[i] > 0)
                next = i;
        for (int i = 0; i < str.length(); i++)
            if (prev == -1 || (next != -1 && prev >= next))
            {
                while (str[idx] != next + '0')
                {
                    stock2[str[idx] - '0']--;
                    stock1[str[idx] - '0']++;
                    if (prev == -1 || prev > str[idx] - '0')
                        prev = str[idx] - '0';
                    idx++;
                }
                ans += str[idx++];
                stock2[next]--;
                next = -1;
                for (int j = 9; j >= 0; j--)
                    if (stock2[j] > 0)
                        next = j;
            }
            else
            {
                ans += min(prev + '1', (int)'9');
                stock1[prev]--;
                prev = -1;
                for (int j = 9; j >= 0; j--)
                    if (stock1[j] > 0)
                        prev = j;
            }
        cout << ans << endl;
    }
    return 0;
}