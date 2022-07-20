// 5:55 - 6:29
#include <iostream>
#include <cassert>
using namespace std;
#define LETTERS 26

int main(void)
{
    int tests, n;
    cin >> tests;
    int numberOf[LETTERS];
    int inFinal[LETTERS];
    for (int test = 0; test < tests; test++)
    {
        for (int i = 0; i < LETTERS; i++)
            numberOf[i] = inFinal[i] = 0;
        cin >> n;
        string s;
        for (int i = 0; i < 2 * n; i++)
        {
            cin >> s;
            for (char ch : s)
                numberOf[ch - 'a']++;
        }
        cin >> s;
        for (char ch : s)
            inFinal[ch - 'a']++;
        int ans = -1;
        for (int i = 0; i < LETTERS; i++)
            if ((numberOf[i] - inFinal[i]) % 2)
            {
                assert(ans == -1);
                ans = i;
            }
        assert(ans != -1);
        char chAns = ans + 'a';
        cout << chAns << endl;
    }
    return 0;
}