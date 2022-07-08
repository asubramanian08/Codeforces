// Official: Failed on test 4
#include <iostream>
using namespace std;

#define MAX_WORKERS 200000
int tests, workerCt, taskCt, task;
int workers[MAX_WORKERS];

bool timeTester(int time)
{
    int remainder = 0;
    for (int i = 0; i < workerCt; i++)
        if (workers[i] > time)
            remainder += (workers[i] - time);
        else
            remainder -= (time - workers[i]) / 2;
    return remainder <= 0;
}

int main(void)
{
    cin >> tests;
    for (int test = 0; test < tests; test++)
    {
        cin >> workerCt >> taskCt;
        for (int i = 0; i < workerCt; i++)
            workers[i] = 0;
        for (int i = 0; i < taskCt; i++)
        {
            cin >> task;
            workers[task - 1]++;
        }
        int lo = 0, hi = taskCt * 2;
        while (hi - lo > 1)
            if (int mid = (hi + lo) / 2; timeTester(mid))
                hi = mid;
            else
                lo = mid;
        cout << hi << endl;
    }
    return 0;
}