// Official: Correct
#include <iostream>
#include <set>
using namespace std;

#define MAX_WORKERS 200000
int tests, workerCt, taskCt, task;
int workers[MAX_WORKERS];

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
        multiset<int> s;
        for (int i = 0; i < workerCt; i++)
            s.insert(workers[i]);
        while (*s.rbegin() - *s.begin() > 2)
        {
            int i1 = *s.rbegin(), i2 = *s.begin();
            s.erase(s.lower_bound(i1));
            s.erase(s.begin());
            s.insert(i1 - 1);
            s.insert(i2 + 2);
        }
        cout << *s.rbegin() << endl;
    }
    return 0;
}