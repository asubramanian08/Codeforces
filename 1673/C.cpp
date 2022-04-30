// Official: Correct
#include <iostream>
using namespace std;

#define MAX_NUM 40100
#define MOD 1000000007

bool is_palendrome(int num)
{
    int digits[5];
    for (int i = 0; i < 5; i++)
    {
        digits[i] = num % 10;
        num /= 10;
    }
    int start = 4;
    while (digits[start] == 0)
        start--;
    for (int i = 0; i <= start; i++)
        if (digits[i] != digits[start - i])
            return false;
    return true;
}

int main(void)
{
    int tests;
    cin >> tests;
    long long waysToGet[MAX_NUM] = {0};
    waysToGet[0] = 1;
    for (int i = 1; i < MAX_NUM; i++)
        if (is_palendrome(i))
            for (int j = 0; j < MAX_NUM - i - 1; j++)
                waysToGet[j + i] = (waysToGet[j + i] + waysToGet[j]) % MOD;
    for (int test = 0; test < tests; test++)
    {
        int query;
        cin >> query;
        cout << waysToGet[query] << endl;
    }
    return 0;
}