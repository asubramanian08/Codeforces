// Official: Wrong on test 3
#include <iostream>
using namespace std;
#define SECT 512

int main(void)
{
    int tests, n;
    // int longestChain[SECT];
    cin >> tests;
    while (tests--)
    {
        cin >> n;
        int *arr = new int[n];
        int *longestChain = new int[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int totalLong = 0, currLong, goTill;
        for (int i = 0; i < n; i += SECT)
        {
            currLong = 1;
            longestChain[i] = currLong;
            goTill = min(i + SECT, n);
            for (int j = i + 1; j < goTill; j++)
            {
                longestChain[j] = 0;
                for (int k = i; k < j; k++)
                    if ((arr[k] ^ j) < (arr[j] ^ k))
                        longestChain[j] = max(longestChain[j], longestChain[k]);
                longestChain[j]++;
                currLong = max(currLong, longestChain[j]);
            }
            totalLong += currLong;
        }
        cout << totalLong << endl;
    }
    return 0;
}