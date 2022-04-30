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
        int totalCharValue = 0;
        for (const char ch : str)
            totalCharValue += ch - 'a' + 1;
        if (str.length() % 2 == 0)
            cout << "Alice " << totalCharValue << endl;
        else
        {
            int Alice = max(totalCharValue - (str.front() - 'a' + 1),
                            totalCharValue - (str.back() - 'a' + 1));
            int Bob = totalCharValue - Alice;
            if (Alice > Bob)
                cout << "Alice " << (Alice - Bob) << endl;
            else
                cout << "Bob " << (Bob - Alice) << endl;
        }
    }
    return 0;
}