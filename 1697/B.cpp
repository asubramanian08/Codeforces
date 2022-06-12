// Official: Correct
#include <iostream>
#include <algorithm>
using namespace std;

long long askPS(long long *ps, int idx)
{
    if (idx < 0)
        return 0;
    return ps[idx];
}

int main(void)
{
    int itemCt, queries;
    cin >> itemCt >> queries;
    int *items = new int[itemCt];
    for (int i = 0; i < itemCt; i++)
        cin >> items[i];
    sort(items, items + itemCt);
    long long *ps = new long long[itemCt];
    ps[0] = items[0];
    for (int i = 1; i < itemCt; i++)
        ps[i] = ps[i - 1] + items[i];
    for (int q = 0; q < queries; q++)
    {
        int toBuy, free;
        cin >> toBuy >> free;
        cout << (askPS(ps, itemCt - toBuy + free - 1) - askPS(ps, itemCt - toBuy - 1)) << endl;
    }
    delete[] items;
    delete[] ps;
    return 0;
}