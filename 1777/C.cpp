// Official: Correct
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 100010

int main(void)
{
    ios_base::sync_with_stdio(false);
    vector<int> factors[MAX];
    for (int i = 1; i < MAX; i++)
        for (int j = 0; j < MAX; j += i)
            factors[j].push_back(i);
    int tests, n, m, smartness[MAX], topics[MAX];
    cin >> tests;
    while (tests--)
    {
        cin >> n >> m;
        for (int i = 0; i <= m; i++)
            topics[i] = 0;
        for (int i = 0; i < n; i++)
            cin >> smartness[i];
        sort(smartness, smartness + n);
        int minDist = MAX, j = 0, emptyTopics = m;
        for (int i = 0; i < n; i++)
        {
            for (j = max(i, j); j < n && emptyTopics != 0; j++)
                for (int fact : factors[smartness[j]])
                    if (fact <= m)
                    {
                        if (topics[fact] == 0)
                            emptyTopics--;
                        topics[fact]++;
                    }
            if (emptyTopics == 0)
                minDist = min(minDist, smartness[j - 1] - smartness[i]);
            for (int fact : factors[smartness[i]])
                if (fact <= m)
                {
                    topics[fact]--;
                    if (topics[fact] == 0)
                        emptyTopics++;
                }
        }
        if (minDist == MAX)
            cout << -1 << endl;
        else
            cout << minDist << endl;
    }
    return 0;
}