#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n, m, usedBy[100010] = {0}, x;
vector<int> primeFactors[100010];

string change(bool add, int x)
{
    if ((add && usedBy[x] == x) || (!add && usedBy[x] != x))
        return "Already "s + (add ? "on" : "off");
    if (add)
        for (int j : primeFactors[x])
            if (usedBy[j] != 0)
                return "Conflict with "s + to_string(usedBy[j]);
    for (int j : primeFactors[x])
        usedBy[j] = (add ? x : 0);
    return "Success";
}

int main(void)
{
    cin >> n >> m;
    primeFactors[1].push_back(1);
    for (int i = 2; i <= n; i++)
    {
        if (primeFactors[i].size() == 0)
            for (int j = i + i; j <= n; j += i)
                primeFactors[j].push_back(i);
        primeFactors[i].push_back(i);
    }
    for (int i = 0; i < m; i++)
    {
        char ch;
        cin >> ch >> x;
        cout << change(ch == '+', x) << endl;
    }
    return 0;
}