// Official: Correct
#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int tests, strLen;
    cin >> tests;
    for (int test = 0; test < tests; test++)
    {
        cin >> strLen;
        string s, t;
        cin >> s >> t;
        string ns, nt;
        for (int i = 0; i < strLen; i++)
            if (s[i] != 'b' || t[i] != 'b')
            {
                ns += s[i];
                nt += t[i];
            }
        s = ns;
        t = nt;

        int ct = 0;
        bool is_a = (s[0] == 'a') || (t[0] == 'a');
        int sCt = 0, tCt = 0;
        bool works = true;
        for (int i = 0; i < s.size() && works; i++)
        {
            bool na = (s[i] == 'a') || (t[i] == 'a');
            if (na != is_a)
                works = sCt == tCt;
            is_a = na;
            sCt += s[i] != 'b';
            tCt += t[i] != 'b';
            char ntp = is_a ? 'c' : 'a';
            works = (works) && (s[i] != ntp) && (t[i] != ntp);
        }
        works = works && (sCt == tCt);

        int bs = 0, bt = 0;
        for (int i = 0; i < s.size() && works; i++)
        {
            bs += s[i] == 'b';
            bt += t[i] == 'b';
            is_a = (s[i] == 'a') || (t[i] == 'a');
            if (is_a)
                works = bs <= bt;
            else
                works = bs >= bt;
        }

        cout << (works ? "YES" : "NO") << endl;
    }
    return 0;
}