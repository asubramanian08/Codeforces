// Official: Correct
#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    int tests, n, m, x, y;
    cin >> tests;
    for (int test = 0; test < tests; test++)
    {
        cin >> n >> m;
        int *cost = new int[n];
        for (int i = 0; i < n; i++)
            cin >> cost[i];
        vector<int> *graph = new vector<int>[n];
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y;
            x--, y--;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        if (m % 2 == 0)
        {
            cout << 0 << endl;
            continue;
        }
        int minCost = 10e5, additional;
        for (int i = 0; i < n; i++)
        {
            if (graph[i].size() % 2 == 0)
            {
                additional = 10e5;
                for (int next : graph[i])
                    additional = min(additional, cost[next]);
            }
            else
                additional = 0;
            minCost = min(minCost, additional + cost[i]);
        }
        cout << minCost << endl;
    }
    return 0;
}