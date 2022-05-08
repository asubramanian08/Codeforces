// Official: Unattempted
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
    int tests;
    cin >> tests;
    for (int test = 0; test < tests; test++)
    {
        int len;
        cin >> len;
        char *seq = new char[len];
        for (int i = 0; i < len; i++)
            cin >> seq[i];

        int changes = 0, segs = 1;
        char currType = seq[0];
        bool changeFirst = true;
        for (int i = 0; i < len; i += 2)
            if (seq[i] != seq[i + 1])
                changes++;
            else
            {
                if (changeFirst)
                    changeFirst = false;
                else if (seq[i] != currType)
                    segs++;
                currType = seq[i];
            }
        cout << changes << ' ' << segs << endl;
    }
    return 0;
}