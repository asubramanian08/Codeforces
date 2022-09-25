// Official: Wrong on pretest 2
#include <iostream>
using namespace std;

int main()
{
    int tests, n;
    long double x[100010], t[100010];
    cin >> tests;
    while (tests--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> x[i];
        for (int i = 0; i < n; i++)
            cin >> t[i];
        long double pos = x[0], height = t[0];
        for (int i = 1; i < n; i++)
            if (t[i] > height - abs(x[i] - pos))
            {
                if (t[i] > height)
                {
                    swap(pos, x[i]);
                    swap(height, t[i]);
                }
                long double newPos = 0;
                if (pos < x[i])
                    newPos = x[i] - (height - t[i]);
                else
                    newPos = x[i] + (height - t[i]);
                newPos = (pos + newPos) / 2.0;
                long double newHeight = abs(newPos - pos) + height;
                pos = newPos;
                height = newHeight;
            }
        cout << pos << endl;
    }
    return 0;
}