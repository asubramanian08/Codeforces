// 11:38 - 12:07
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

int tests, n, a, b, p, *ans;
vector<pair<pii, int>> *graph;
vector<long long> b_PS;

void DFS(int nd, long long currA, long long currB)
{
    b_PS.push_back(currB);
    ans[nd] = upper_bound(b_PS.begin(), b_PS.end(), currA) - b_PS.begin() - 1;
    for (auto next : graph[nd])
        DFS(next.second, currA + next.first.first, currB + next.first.second);
    b_PS.pop_back();
}

int main(void)
{
    cin >> tests;
    while (tests--)
    {
        cin >> n;
        graph = new vector<pair<pii, int>>[n];
        for (int i = 1; i < n; i++)
        {
            cin >> p >> a >> b;
            graph[p - 1].push_back(pair(pair(a, b), i));
        }
        ans = new int[n];
        DFS(0, 0, 0);
        for (int i = 1; i < n; i++)
            cout << ans[i] << ' ';
        cout << endl;
    }
}