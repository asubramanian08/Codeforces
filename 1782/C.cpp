// Official: Runtime error on test 2
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;
using pii = pair<int, int>;

int main(void)
{
    ios_base::sync_with_stdio(false);
    int tests, n;
    pii arr[26];
    cin >> tests;
    while (tests--)
    {
        for (int i = 0; i < 26; i++)
            arr[i] = {0, i};
        cin >> n;
        char ch;
        vector<int> input;
        for (int i = 0; i < n; i++)
        {
            cin >> ch;
            arr[ch - 'a'].first++;
            input.push_back(ch - 'a');
        }
        sort(arr, arr + 26, greater<pii>());
        int minCost = n + 1, letters = 0, count = -1;
        for (int i = 0; i < n; i++)
            if (n % (i + 1) == 0)
            {
                int cost = 0;
                count = n / (i + 1);
                for (int j = 0; j <= i; j++)
                    if (arr[j].first < count)
                        cost += count - arr[j].first;
                if (cost < minCost)
                {
                    minCost = cost;
                    letters = i + 1;
                }
            }
        cout << minCost << endl;
        count = n / letters;
        vector<pii> toChange;
        int total = 0;
        for (int i = 0; i < n; i++)
        {
            if (i < letters && arr[i].first > count)
            {
                toChange.push_back({arr[i].first - count, arr[i].second});
                total += toChange.back().first;
            }
            else if (i >= letters && arr[i].first != 0)
            {
                toChange.push_back(arr[i]);
                total += toChange.back().first;
            }
        }
        assert(total == minCost);
        vector<int> changes[26];
        for (int i = 0; i < letters; i++)
            while (arr[i].first < count)
            {
                changes[toChange.back().second].push_back(arr[i].second);
                arr[i].first++;
                toChange.back().first--;
                if (toChange.back().first == 0)
                    toChange.pop_back();
            }
        total = 0;
        for (int i = 0; i < 26; i++)
            total += changes[i].size();
        assert(total == minCost);
        for (int i = 0; i < n; i++)
            if (changes[input[i]].empty())
                cout << ((char)(input[i] + 'a'));
            else
            {
                cout << ((char)(changes[input[i]].back() + 'a'));
                changes[input[i]].pop_back();
            }
        cout << endl;
    }
    return 0;
}