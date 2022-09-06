// Official: TLE on test 9
#include <iostream>
#include <vector>
using namespace std;
using pii = pair<int, int>;

bool vis[200005];
bool edges[200005];
bool ret;
vector<pii> graph[200005];
int tests, n, m, x, y, p1, p2, bad1, bad2;
void DFS(int node, int par, int prevEdge)
{
    vis[node] = true;
    for (pii &i : graph[node])
    {
        if (ret)
            return;
        if (i.first != par && edges[i.second] == false)
        {
            if (!vis[i.first])
                DFS(i.first, node, i.second);
            else
            {
                p1 = min(node, i.first), p2 = max(node, i.first);
                if (p1 == bad1 && p2 == bad2)
                    edges[prevEdge] = true;
                else
                    edges[i.second] = true;
                ret = true;
            }
        }
    }
}

void reset()
{
    ret = false;
    for (int i = 0; i < n; i++)
        vis[i] = false;
    bad1 = bad2 = 0;
}

int main(void)
{
    cin >> tests;
    while (tests--)
    {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            graph[i].clear();
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y;
            x--, y--;
            graph[x].push_back({y, i});
            graph[y].push_back({x, i});
            edges[i] = false;
        }
        reset();
        DFS(0, -1, -1);
        int used1 = p1, used2 = p2;
        reset();
        DFS(0, -1, -1);
        reset();
        if (p1 == used1)
            bad1 = p2, bad2 = used2;
        else if (p1 == used2)
            bad1 = p2, bad2 = used1;
        else if (p2 == used1)
            bad1 = p1, bad2 = used2;
        else if (p2 == used2)
            bad1 = p1, bad2 = used1;
        if (bad1 > bad2)
            swap(bad1, bad2);
        DFS(0, -1, -1);

        for (int i = 0; i < m; i++)
            cout << (edges[i] ? "1" : "0");
        cout << endl;
    }
    return 0;
}