// Official: Correct
#include <iostream>
using namespace std;

int main(void)
{
    int tests, x;
    int arr[3];
    cin >> tests;
    for (int test = 0; test < tests; test++)
    {
        cin >> x >> arr[0] >> arr[1] >> arr[2];
        x--, arr[0]--, arr[1]--, arr[2]--;
        while (x != -1)
        {
            int temp = arr[x];
            arr[x] = -1;
            x = temp;
        }
        bool works = true;
        for (int i = 0; i < 3; i++)
            works = works && arr[i] == -1;
        cout << (works ? "YES" : "NO") << endl;
    }
    return 0;
}