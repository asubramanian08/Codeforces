// Official: Correct
#include <iostream>
#include <queue>
using namespace std;

#define MOD 32768
#define NA -1

int main(void)
{
    int *stepsLeft = new int[MOD + 1];
    for (int i = 1; i < MOD; i++)
        stepsLeft[i] = NA;
    stepsLeft[0] = stepsLeft[MOD] = 0;
    queue<int> q;
    q.push(MOD);
    while (!q.empty())
    {
        int num = q.front();
        q.pop();
        if (stepsLeft[num - 1] == NA)
        {
            stepsLeft[num - 1] = stepsLeft[num] + 1;
            q.push(num - 1);
        }
        if (num % 2 == 0 && stepsLeft[num / 2] == NA)
        {
            stepsLeft[num / 2] = stepsLeft[num] + 1;
            q.push(num / 2);
        }
        if (num % 2 == 0 && stepsLeft[(num + MOD) / 2] == NA)
        {
            stepsLeft[(num + MOD) / 2] = stepsLeft[num] + 1;
            q.push((num + MOD) / 2);
        }
    }
    int tests, start;
    cin >> tests;
    for (int test = 0; test < tests; test++)
    {
        cin >> start;
        cout << stepsLeft[start] << endl;
    }
    return 0;
}