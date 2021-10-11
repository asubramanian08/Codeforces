//Official: incorrect
//After looking at solution
#include <iostream>
#include <string>
#include <map>
#include <queue>
using namespace std;

#define MOD 1000000007
#define mp make_pair

int main(void)
{
    //standard tree
    int levels;
    cin >> levels;
    long long *standard = new long long[levels];
    standard[levels - 1] = 2;
    for (int i = levels - 2; i >= 0; i--)
        standard[i] = (standard[i + 1] * standard[i + 1] * 8) % MOD;

    //up the tree: set up
    int setNodes;
    cin >> setNodes;
    map<string, int> color;
    color["white"] = 0;
    color["yellow"] = 1;
    color["green"] = 2;
    color["blue"] = 3;
    color["orange"] = 4;
    color["red"] = 5;
    map<long long, int> require;
    for (int i = 0; i < setNodes; i++)
    {
        long long node;
        string c;
        cin >> node >> c;
        require[node] = color[c];
    }
    queue<long long> q;
    map<long long, long long[3]> ways;
    auto firstBit = [](long long num)
    {
        int bitNum = 0;
        while (num = num >> 1)
            bitNum++;
        return bitNum;
    };

    //build up tree
    auto orderings = [&ways, &standard, levels, &firstBit](long long node, int color)
    {
        long long left, right, level = firstBit(node);
        if (level >= levels - 1)
            return (long long)1;
        if (ways.find(2 * node) != ways.end())
            left = ways[2 * node][0] + ways[2 * node][1] +
                   ways[2 * node][2] - ways[2 * node][color];
        else
            left = 2 * standard[level + 1];
        if (ways.find(2 * node + 1) != ways.end())
            right = ways[2 * node + 1][0] + ways[2 * node + 1][1] +
                    ways[2 * node + 1][2] - ways[2 * node + 1][color];
        else
            right = 2 * standard[level + 1];
        left %= MOD, right %= MOD;
        return (left * right) % MOD;
    };
    auto iter = require.rbegin();
    while (iter != require.rend() || !q.empty())
        if (q.empty() || (iter != require.rend() && q.front() <= iter->first))
        {
            long long node = iter->first;
            ways[node][0] = ways[node][1] = ways[node][2] = 0;
            ways[node][iter->second / 2] = orderings(node, iter->second / 2);
            q.push(node / 2);
            iter++;
        }
        else
        {
            long long node = q.front();
            q.pop();
            if (ways.find(node) != ways.end())
                continue;
            for (int i = 0; i < 3; i++)
                ways[node][i] = (2 * orderings(node, i)) % MOD;
            q.push(node / 2);
        }

    //print and delete
    long long ans = ((ways[1][0] + ways[1][1]) % MOD + ways[1][2]) % MOD;
    cout << ans << endl;
    delete[] standard;
    return 0;
}