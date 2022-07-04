// Official: Unattempted
#include <iostream>
using namespace std;
#define MAX_LEN 5000

int arr[MAX_LEN];
int ps[MAX_LEN][MAX_LEN];

int getPS(int i, int l, int r)
{
    int ret = ps[i][r];
    int other = 0;
    if (l != 0)
        other = ps[i][l - 1];
    return ret - other;
}

int seqLen(int len, int a)
{
    int leftOver = -1, LO_CT = 0, last = 0, ret = 0;
    for (int i = 0; i < len; i++)
    {
        if (arr[i] != a && i != len - 1)
            continue;
        if (arr[i] == a)
            ret++;
        else
            i = len;
        int maxCt = 0, var = -1;
        for (int j = last; j < i; j++)
        {
            int currCt = getPS(arr[j], last, i - 1);
            if (arr[j] == leftOver)
                currCt += LO_CT;
            if (currCt > maxCt)
            {
                maxCt = currCt;
                var = arr[j];
            }
        }
        int totalVars = i - last + LO_CT;
        if (maxCt * 2 > totalVars)
        {
            leftOver = var;
            LO_CT = maxCt - (totalVars - maxCt);
        }
        else
        {
            leftOver = -1;
            LO_CT = totalVars % 2;
        }
        last = i + 1;
        int diff = min(LO_CT, ret);
        ret -= diff;
        LO_CT -= diff;
    }
    return ret;
}

int main(void)
{
    int tests, len;
    cin >> tests;
    for (int test = 0; test < tests; test++)
    {
        cin >> len;
        for (int i = 0; i < len; i++)
        {
            cin >> arr[i];
            arr[i]--;
        }
        for (int i = 0; i < len; i++)
        {
            ps[i][0] = (arr[0] == i);
            for (int j = 1; j < len; j++)
                ps[i][j] = ps[i][j - 1] + (arr[j] == i);
        }
        int maxSeq = 0;
        for (int i = 0; i < len; i++)
            if (ps[i][len - 1] > maxSeq)
                maxSeq = max(maxSeq, seqLen(len, i));
        cout << maxSeq << endl;
    }
    return 0;
}