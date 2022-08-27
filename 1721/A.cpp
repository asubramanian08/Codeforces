// Official: Correct
#include <iostream>
using namespace std;

int main(void)
{
    int tests, let[26] = {0};
    char ch;
    cin >> tests;
    while (tests--)
    {
        for (int i = 0; i < 4; i++)
        {
            cin >> ch;
            let[ch - 'a']++;
        }
        int totalColors = 0;
        for (int i = 0; i < 26; i++)
            if (let[i] != 0)
            {
                totalColors++;
                let[i] = 0;
            }
        cout << (totalColors - 1) << endl;
    }
}