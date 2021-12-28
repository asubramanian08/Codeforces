// Official: Correct
#include <iostream>
using namespace std;

int main(void)
{
    int tests;
    cin >> tests;
    for (int test = 0; test < tests; test++)
    {
        int rows, cols, pos_r, pos_c, dirty_r, dirty_c;
        cin >> rows >> cols >> pos_r >> pos_c >> dirty_r >> dirty_c;
        int ans_r = dirty_r >= pos_r ? dirty_r - pos_r : (rows - pos_r) + (rows - dirty_r);
        int ans_c = dirty_c >= pos_c ? dirty_c - pos_c : (cols - pos_c) + (cols - dirty_c);
        cout << min(ans_r, ans_c) << endl;
    }
    return 0;
}