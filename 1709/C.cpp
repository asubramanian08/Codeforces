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
        string str;
        cin >> str;
        if (str[0] == '?')
            str[0] = '(';
        int *open = new int[str.length()];
        open[0] = 1;
        int q = 0, o = 1, c = 0;
        for (int i = 1; i < str.length(); i++)
        {
            open[i] = open[i - 1] + (str[i] != ')' ? 1 : -1);
            if (str[i] == '(')
                o++;
            else if (str[i] == '?')
                q++;
            else
                c++;
        }
        int toRemove = open[str.length() - 1];
        bool works = true;
        for (int i = str.length() - 1; i >= 0 && works; i--)
        {
            open[i] -= toRemove;
            if (toRemove == 0)
            {
                if (open[i] < 2)
                    break;
                if (str[i] == '?')
                    works = false;
            }
            else if (str[i] == '?')
                toRemove -= 2;
        }
        cout << (works ? "YES" : "NO") << endl;
    }
    return 0;
}