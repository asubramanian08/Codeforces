// Official: Correct
#include <iostream>
#include <algorithm>
using namespace std;

// BIT or fenwick tree
class BIT
{
private:
    int *bTree;
    int elements;

public:
    BIT(int elem);
    BIT(int elem, int *initialize, int numInit);
    ~BIT() { delete[] bTree; }
    int query(int node);
    void updt(int node, int cng);
};
BIT::BIT(int elem)
{
    elements = elem;
    bTree = new int[elem + 1];
    for (int i = 1; i <= elem; i++)
        bTree[i] = 0;
}
BIT::BIT(int elem, int *initialize, int numInit)
{
    elements = elem;
    bTree = new int[elem + 1];
    for (int i = 1; i <= elem; i++)
        bTree[i] = 0;
    for (int i = 0; i < numInit; i++)
        updt(i, initialize[i]);
}
int BIT::query(int node)
{
    if (node == -1)
        return 0;
    int sum = 0;
    for (int i = node + 1; i > 0; i -= (i & -i))
        sum += bTree[i];
    return sum;
}
void BIT::updt(int node, int cng)
{
    for (int i = node + 1; i <= elements; i += (i & -i))
        bTree[i] += cng;
}

int main(void)
{
    int tests;
    cin >> tests;
    for (int test = 0; test < tests; test++)
    {
        int len;
        cin >> len;
        int *seq = new int[len];
        for (int i = 0; i < len; i++)
            cin >> seq[i];
        BIT bit(len + 1);
        long long ans = 0;
        for (int b = 1; b < len; b++)
        {
            bit.updt(seq[b - 1], 1);
            long long valuesGreater = 0;
            for (int c = len - 2; c > b; c--)
            {
                valuesGreater += seq[b] > seq[c + 1];
                ans += bit.query(seq[c]) * valuesGreater;
            }
        }
        cout << ans << endl;
        delete[] seq;
    }
    return 0;
}