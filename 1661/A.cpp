// Official: Correct
#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
    int tests, arrLen;
    cin >> tests;
    for (int test = 0; test < tests; test++)
    {
        cin >> arrLen;
        long long *arrA = new long long[arrLen];
        for (long long i = 0; i < arrLen; i++)
            cin >> arrA[i];
        long long *arrB = new long long[arrLen];
        for (long long i = 0; i < arrLen; i++)
            cin >> arrB[i];
        long long minCost = 0;
        for (long long i = 1; i < arrLen; i++)
            minCost += min(abs(arrA[i] - arrA[i - 1]) + abs(arrB[i] - arrB[i - 1]),
                           abs(arrA[i] - arrB[i - 1]) + abs(arrB[i] - arrA[i - 1]));
        cout << minCost << endl;
    }
    return 0;
}