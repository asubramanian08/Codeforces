// Official: Correct
#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tests, n, a[110], b;
    cin >> tests;
    while (tests--)
    {
        cin >> n;
        bool match0 = true, match1 = true;
        int needed0 = 0;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
        {
            cin >> b;
            if (b == 0 && a[i] == 1)
                match0 = false, needed0++;
            if (b == 1 && a[i] == 0)
                match1 = false, needed0--;
        }
        int ans = abs(needed0) + (match0 == false && match1 == false);
        cout << ans << endl;
    }
    return 0;
}