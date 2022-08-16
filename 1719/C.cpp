// Official: Failed on test 2
#include <iostream>
using namespace std;
using pii = pair<long long, long long>;

int main(void)
{
    long long tests, n, q, largest, lid, curr;
    cin >> tests;
    for (int test = 0; test < tests; test++)
    {
        cin >> n >> q;
        long long *arr = new long long[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        pii *reign = new pii[n];
        for (int i = 0; i < n; i++)
            reign[i] = pii(0, 0);
        reign[0].first = 1;
        lid = 0;
        largest = arr[0];
        for (int i = 1; i < n; i++)
        {
            curr = arr[i];
            if (largest > curr)
                reign[lid].second++;
            else
            {
                largest = curr;
                lid = i;
                reign[lid].first = i;
                reign[lid].second = 1;
            }
        }
        long long part, rounds;
        for (int i = 0; i < q; i++)
        {
            cin >> part >> rounds;
            part--;
            if (arr[part] == largest)
                cout << (rounds - reign[part].first + 1) << endl;
            else
                cout << min(rounds - reign[part].first + 1, reign[part].second) << endl;
        }
    }
    return 0;
}