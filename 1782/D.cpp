// Official: Unattempted
#include <iostream>
#include <vector>
using namespace std;
using pii = pair<int, int>;

int main(void)
{
    ios_base::sync_with_stdio(false);
    int tests, n;
    pair<pii, pii> rects[200010];
    cin >> tests;
    while (tests--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> rects[i].first.first >> rects[i].first.second >>
                rects[i].second.first >> rects[i].second.second;
        vector<pii> full, top, bottom;
        for (int i = 0; i < n; i++)
            if (rects[i].first.first != rects[i].second.first)
                full.push_back({rects[i].first.second, -i}),
                    full.push_back({rects[i].second.second, i});
            else if (rects[i].first.first == 1)
                top.push_back({rects[i].first.second, -i}),
                    top.push_back({rects[i].second.second, i});
            else
                bottom.push_back({rects[i].first.second, -i}),
                    bottom.push_back({rects[i].second.second, i});
        sort(full.begin(), full.end());
        sort(top.begin(), top.end());
        sort(bottom.begin(), bottom.end());
        int doneTill = 0;
        for (int i = 0; i < full.size(); i++)
    }
    return 0;
}