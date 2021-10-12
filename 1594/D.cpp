//Official: correct
#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define NA -1
using pib = pair<int, bool>;
int componentCount;
int dfs(bool *vis, bool *belief, vector<pib> *players, bool currBelief, int node)
{
    //handle node
    if (vis[node])
        return belief[node] == currBelief ? 0 : NA;
    vis[node] = true;
    componentCount++;
    belief[node] = currBelief;

    //other nodes: answer
    int ans = currBelief, curr;
    for (pib next : players[node])
    {
        curr = dfs(vis, belief, players, currBelief ^ next.second, next.first);
        if (curr == NA)
            return NA;
        ans += curr;
    }
    return ans;
}

int main(void)
{
    //read
    int tests;
    cin >> tests;
    for (int i = 0; i < tests; i++)
    {
        //read: form connections
        int numPlayers, comments;
        cin >> numPlayers >> comments;
        vector<pib> *players = new vector<pib>[numPlayers];
        for (int i = 0; i < comments; i++)
        {
            int p1, p2;
            string comment;
            cin >> p1 >> p2 >> comment;
            p1--, p2--;
            players[p1].push_back(pib(p2, comment != "crewmate"));
            players[p2].push_back(pib(p1, comment != "crewmate"));
        }

        //count imposters
        bool *vis = new bool[numPlayers];
        for (int i = 0; i < numPlayers; i++)
            vis[i] = false;
        bool *belief = new bool[numPlayers];
        int imposters = 0, currImp;
        for (int i = 0; i < numPlayers; i++)
            if (!vis[i])
            {
                componentCount = 0;
                currImp = dfs(vis, belief, players, false, i);
                if (currImp == NA)
                {
                    imposters = NA;
                    break;
                }
                imposters += max(currImp, componentCount - currImp);
            }
        for (int i = 0; i < numPlayers; i++)
            imposters += vis[i] == false && imposters != NA;
        cout << imposters << endl;
    }
    return 0;
}