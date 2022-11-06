// Official: Correct
#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    long long tests, n;
    cin >> tests;
    while (tests--)
    {
        cin >> n;
        string str;
        cin >> str;
        char last = '2';
        long long lasted = 0, ones = 0, zeros = 0, maxLen = 1;
        for (char ch : str)
        {
            ones += ch == '1';
            zeros += ch == '0';
            if (ch == last)
                maxLen = max(maxLen, ++lasted);
            else
                last = ch, lasted = 1;
        }
        cout << max(ones * zeros, maxLen * maxLen) << endl;
    }
    return 0;
}