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
        cout << changes << ' ';

        vector<int> v;
        currLen = 0;
        currType = seq[0];
        for (int i = 0; i < len; i++)
            if (seq[i] == currType)
                currLen++;
            else
            {
                v.push_back(currLen);
                currLen = 1;
                currType = seq[i];
            }
        v.push_back(currLen);
        len = v.size();
        int *next = new int[len];
        int *prev = new int[len];
        for (int i = 0; i < len; i++)
        {
            next[i] = i + 1 == len ? -1 : i + 1;
            prev[i] = i - 1;
        }
        int first = 0;
        int segs = len;
        if (v[0] == 1 && v[1] > 2)
        {
            v[0]--, v[1]++;
            first = v[1];
            prev[1] = -1;
            segs--;
        }
        for (int i = 1; i < len - 1; i++)
        {
            if (v[i] == 1)
            {
                v[i + 1] += v[i - 1] + v[i];
                segs -= 2;
            }
            if (v[i] == 2 && v[i - 1] % 2 == 1)
            {
                v[i + 1] += v[i - 1] + v[i];
                segs -= 2;
            }
        }

        cout << segs << endl;
        /*

        int changes = 0, segs = 1, currLen = 0;
        char currType = seq[0];
        for (int i = 0; i < len; i++)
            if (seq[i] == currType)
                currLen++;
            else
            {
                if (currLen > 1)
                    segs++;
                if (currLen % 2 == 1)
                    changes++;
                if (currLen % 2 == 1)
                    if (currLen == 1)
                        currLen = 2;
                    else
                        currLen = 0;
                else
                    currLen = 1;
                currType = seq[i];
            }
        cout << changes << ' ' << segs << endl;*/
    }
    return 0;
}