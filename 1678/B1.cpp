// Official: Correct
#include <iostream>
#include <algorithm>
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
        int changes = 0, currLen = 0;
        char currType = seq[0];
        for (int i = 0; i < len; i++)
            if (seq[i] == currType)
                currLen++;
            else
            {
                if (currLen % 2 == 1)
                    changes++;
                if (currLen % 2 == 1)
                    currLen = 0;
                else
                    currLen = 1;
                currType = seq[i];
            }
        cout << changes << endl;
    }
    return 0;
}