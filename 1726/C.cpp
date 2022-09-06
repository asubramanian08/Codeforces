// Official: Correct
#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int tests, n;
    cin >> tests;
    while (tests--)
    {
        cin >> n;
        string str;
        cin >> str;
        char last = str[0];
        int ans = n + 1;
        for (char ch : str)
        {
            if (ch == ')' && last == '(')
                ans--;
            last = ch;
        }
        cout << ans << endl;
    }
    return 0;
}