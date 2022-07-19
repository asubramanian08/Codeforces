// 5:21 - 5:57
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

        int *zeroSS = new int[str.size()];
        int *oneSS = new int[str.size()];
        int zeros = 0, ones = 0;
        for (int i = str.size() - 1; i >= 0; i--)
        {
            if (str[i] == '0')
                zeros++;
            else
                ones++;
            zeroSS[i] = zeros;
            oneSS[i] = ones;
        }

        int idx = str.size() - zeros, ans;
        if (zeros == 0)
            ans = 0;
        else
            ans = max(oneSS[idx], zeros - zeroSS[idx]);
        int zeroCost = zeros, oneCost = 0;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == '0')
                zeroCost--;
            else
                oneCost++;
            int cost = max(oneCost, zeroCost);
            if (zeroCost > oneCost)
            {
                int idx = str.size() - (zeroCost - oneCost);
                int new1Cost = oneCost + oneSS[idx];
                int new0Cost = zeroCost - zeroSS[idx];
                cost = max(new1Cost, new0Cost);
            }
            ans = min(ans, cost);
        }

        cout << ans << endl;
    }
    return 0;
}