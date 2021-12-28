// Official: Correct
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using pii = pair<int, int>;
#define NA -1

// data
int nodes, canRemove;
string letter;
pii *children;
vector<int> order;
string nextDiff;
string leastLexOrder;
int currPos = 0;

void inorder(int node)
{
    if (node == NA)
        return;
    inorder(children[node].first);
    order.push_back(node);
    inorder(children[node].second);
}

bool least_lex(int node, bool canDup, int fixLen)
{
    if (node == NA)
        return false;
    bool mustDup = least_lex(children[node].first, canDup, fixLen + 1);
    leastLexOrder += letter[node];
    bool dup = false;
    if (mustDup)
        dup = true;
    else if (canDup && fixLen <= canRemove && letter[node] < nextDiff[currPos])
    {
        dup = true;
        canRemove -= fixLen;
    }
    if (dup)
        leastLexOrder += letter[node];
    currPos++;
    least_lex(children[node].second, dup, 1);
    return dup;
}

int main(void)
{
    // read
    cin >> nodes >> canRemove;
    cin >> letter;
    children = new pii[nodes];
    for (int i = 0; i < nodes; i++)
    {
        cin >> children[i].first >> children[i].second;
        children[i].first--, children[i].second--;
    }

    // run, find leastLexOrder
    inorder(0); // regular inorder
    for (int i = 0; i < nodes; i++)
        nextDiff += letter[order[i]];
    nextDiff[nodes - 1] = 'a' - 1;
    for (int i = nodes - 2; i >= 0; i--)
        if (letter[order[i]] != letter[order[i + 1]])
            nextDiff[i] = letter[order[i + 1]];
        else
            nextDiff[i] = nextDiff[i + 1];
    least_lex(0, true, 1);

    // print and delete
    cout << leastLexOrder << endl;
    delete[] children;
    return 0;
}