// Official: Correct
#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    int tests, seqLen;
    cin >> tests;
    for (int test = 0; test < tests; test++)
    {
        cin >> seqLen;
        int *seq = new int[seqLen];
        for (int i = 0; i < seqLen; i++)
            cin >> seq[i];
        sort(seq, seq + seqLen);
        int zeros = (seq[0] == 0);
        bool repeats = false;
        for (int i = 1; i < seqLen; i++)
            if (seq[i] == 0)
                zeros++;
            else if (seq[i] == seq[i - 1])
                repeats = true;
        int ans = seqLen - zeros;
        if (zeros == 0 && !repeats)
            ans++;
        cout << ans << endl;
    }
    return 0;
}