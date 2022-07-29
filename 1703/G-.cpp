// 5:38-6:19 #WRONG
#include <iostream>
using namespace std;
#define MAX_LOG 35

long long tests, n, k, oneCount[MAX_LOG] = {0};
void editMaxLog(long long x, bool add)
{
    for (int i = 0; i < MAX_LOG; i++, x /= 2)
        oneCount[i] += (add ? +1 : -1) * (x % 2);
}

int main(void)
{
    cin >> tests;
    for (int test = 0; test < tests; test++)
    {
        cin >> n >> k;
        long long *a = new long long[n];
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            editMaxLog(a[i], true);
            sum += a[i];
        }
        long long totalValue = sum, halved = 0;
        for (int i = 0; i < n; i++)
        {
            long long goodKey = totalValue - k;
            long long halvedSum = (sum - oneCount[halved]) / 2;
            long long badKey = totalValue - (sum - halvedSum);
            totalValue = goodKey;
            if (badKey >= goodKey)
            {
                totalValue = badKey;
                halved++;
                sum = halvedSum;
            }
            sum -= a[i] >> halved;
            editMaxLog(a[i], false);
        }
        cout << totalValue << endl;
    }
    return 0;
}