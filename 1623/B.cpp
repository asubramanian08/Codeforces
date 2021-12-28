// Official: Correct
#include <iostream>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

int main(void)
{
    int tests, length;
    cin >> tests;
    for (int test = 0; test < tests; test++)
    {
        cin >> length;
        pair<pii, int> *ranges = new pair<pii, int>[length];
        for (int i = 0; i < length; i++)
            cin >> ranges[i].first.first >> ranges[i].first.second;
        sort(ranges, ranges + length, [](pair<pii, int> p1, pair<pii, int> p2)
             { return p1.first.second - p1.first.first < p2.first.second - p2.first.first; });
        int *rightSide = new int[length + 1];
        for (int i = 0; i <= length; i++)
            rightSide[i] = i - 1;
        for (int i = 0; i < length; i++)
        {
            ranges[i].second = rightSide[ranges[i].first.first] + 1;
            rightSide[ranges[i].first.first] = ranges[i].first.second;
            cout << ranges[i].first.first << ' '
                 << ranges[i].first.second << ' '
                 << ranges[i].second << endl;
        }
        delete[] ranges;
        delete[] rightSide;
    }
    return 0;
}