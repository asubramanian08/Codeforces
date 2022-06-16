// Official: Failed on test 4
#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int tests, len;
    cin >> tests;
    for (int test = 0; test < tests; test++)
    {
        cin >> len;
        string str;
        cin >> str;
        int ans = 1;
        for (int i = 1; i < str.size(); i++)
            if (str[i - 1] != str[i])
                ans += i + 1;
            else
                ans += 1;
        cout << ans << endl;
    }
    return 0;
}