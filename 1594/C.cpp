// Official: Unattempted
// After looking at solution
#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    // read
    int tests;
    cin >> tests;
    for (int i = 0; i < tests; i++)
    {
        int maxOper;
        char target;
        string str;
        cin >> maxOper >> target >> str;

        // tests outputs
        bool works = true;
        for (char ch : str)
            if (ch != target)
                works = false;
        if (works)
            cout << 0 << endl;
        for (int j = 2; j <= maxOper && !works; j++)
        {
            works = true;
            for (int k = j - 1; k < str.length(); k += j)
                if (str[k] != target)
                    works = false;
            if (works)
                cout << 1 << endl
                     << j << endl;
        }
        if (!works)
            cout << 2 << endl
                 << (maxOper - 1) << ' '
                 << maxOper << endl;
    }
    return 0;
}