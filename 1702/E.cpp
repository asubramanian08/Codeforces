// 10:55 - 11:15
#include <iostream>
#include <vector>
using namespace std;

int tests, n, a, b, *color, *domino;
vector<int> *graph;
bool DFS(int nd, int c)
{
    if (color[nd] != -1)
        return color[nd] == c;
    color[nd] = c;
    for (int next : graph[nd])
        if (DFS(next, 1 - c) == false)
            return false;
    return true;
}

int main(void)
{
    cin >> tests;
    for (int test = 0; test < tests; test++)
    {
        cin >> n;
        graph = new vector<int>[n];
        domino = new int[n];
        for (int i = 0; i < n; i++)
            domino[i] = -1;
        for (int i = 0; i < n; i++)
        {
            cin >> a >> b;
            a--, b--;
            if (domino[a] == -1)
                domino[a] = i;
            else if (domino[a] >= 0)
            {
                graph[i].push_back(domino[a]);
                graph[domino[a]].push_back(i);
                domino[a] = -2;
            }
            if (domino[b] == -1)
                domino[b] = i;
            else if (domino[b] >= 0)
            {
                graph[i].push_back(domino[b]);
                graph[domino[b]].push_back(i);
                domino[b] = -2;
            }
        }
        color = new int[n];
        for (int i = 0; i < n; i++)
            color[i] = -1;
        bool works = true;
        for (int i = 0; i < n && works; i++)
            works = (domino[i] == -2);
        for (int i = 0; i < n && works; i++)
            if (color[i] == -1 && !DFS(i, 0))
                works = false;
        cout << (works ? "YES" : "NO") << endl;
    }
    return 0;
}