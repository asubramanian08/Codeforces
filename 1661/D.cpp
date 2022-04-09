// Official: Correct
#include <iostream>
#include <cassert>
using namespace std;

int main(void)
{
    int elementCt, coverSize;
    cin >> elementCt >> coverSize;
    long long *threshold = new long long[elementCt];
    for (int i = 0; i < elementCt; i++)
        cin >> threshold[i];
    long long currentCovers = 0, totalCovers = 0, removed = 0;
    long long *coverEnds = new long long[elementCt];
    for (int i = 0; i < elementCt; i++)
        coverEnds[i] = 0;
    for (int i = elementCt - 1; i >= coverSize; i--)
    {
        removed -= currentCovers;
        currentCovers -= coverEnds[i];
        long long addCovers = (threshold[i] - removed + coverSize - 1) / coverSize;
        addCovers = max(addCovers, 0ll);
        totalCovers += addCovers;
        currentCovers += addCovers;
        coverEnds[i - coverSize] += addCovers;
        removed += addCovers * coverSize;
        assert(removed >= threshold[i]);
    }
    for (int i = coverSize - 1; i >= 0; i--)
    {
        removed -= currentCovers;
        currentCovers -= coverEnds[i];
        long long addCovers = (threshold[i] - removed + i) / (i + 1);
        addCovers = max(addCovers, 0ll);
        totalCovers += addCovers;
        currentCovers += addCovers;
        removed += addCovers * (i + 1);
        assert(removed >= threshold[i]);
    }
    cout << totalCovers << endl;
    return 0;
}