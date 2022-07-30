// 3:40 - 4:45
#include <iostream>
#include <vector>
using namespace std;
#define MAX_VERT 1'000'000'005
#define NA -1

int n, m, *a, x1, x2;
long long k, *vis;
vector<int> *graph;

long long DFS(int x, long long depth, int limit)
{
    if (a[x] > limit)
        return false;
    depth++;
    if (vis[x] == 0 || depth == k)
        return k;
    if (vis[x] != NA)
        return vis[x];
    vis[x] = 0;
    long long maxLen = 0;
    for (int next : graph[x])
        maxLen = max(maxLen, DFS(next, depth, limit));
    return (vis[x] = maxLen + 1);
}

bool isAllowed(int maxVert)
{
    for (int i = 0; i < n; i++)
        vis[i] = NA;
    for (int i = 0; i < n; i++)
        if (vis[i] == NA && DFS(i, 0, maxVert) >= k)
            return true;
    return false;
}

int main(void)
{
    cin >> n >> m >> k;
    a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    graph = new vector<int>[n];
    for (int i = 0; i < m; i++)
    {
        cin >> x1 >> x2;
        graph[x1 - 1].push_back(x2 - 1);
    }

    int l = 0, h = MAX_VERT;
    vis = new long long[n];
    while (h - l > 1)
        if (int mid = (h + l) / 2; isAllowed(mid))
            h = mid;
        else
            l = mid;
    cout << (h == MAX_VERT ? NA : h) << endl;
    return 0;
}