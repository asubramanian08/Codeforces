// Official: Failed on test 3
#include <iostream>
#include <algorithm>
using namespace std;

int res(long long ones, long long twos)
{
    if (twos - 1 > ones)
    {
        long long change = (twos - ones + 1) / 3;
        ones += 2 * change;
        twos -= change;
        if (change > 0 && ones - 2 >= twos)
        {
            ones -= 2;
            twos += 1;
        }
        if (twos - 1 > ones)
        {
            twos -= 1;
            ones += 2;
        }
    }
    long long usedDays = min(ones, twos);
    ones -= usedDays, twos -= usedDays;
    long long ans = 2 * usedDays;
    if (ones > 0)
        ans += 1 + 2 * (ones - 1);
    if (twos > 0)
        ans += 2 * twos;
    return ans;
}

int main(void)
{
    int tests, treeCt;
    cin >> tests;
    for (int test = 0; test < tests; test++)
    {
        cin >> treeCt;
        int *heights = new int[treeCt];
        for (int i = 0; i < treeCt; i++)
            cin >> heights[i];
        sort(heights, heights + treeCt);
        for (int i = 0; i < treeCt; i++)
            heights[i] = heights[treeCt - 1] - heights[i];
        long long twos = 0, ones = 0;
        for (int i = 0; i < treeCt; i++)
            twos += heights[i] / 2, ones += heights[i] % 2;
        cout << min(res(ones, twos), res(treeCt - ones, twos + ones)) << endl;
    }
    return 0;
}