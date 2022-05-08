// Official: Correct
#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int tests;
    cin >> tests;
    for (int test = 0; test < tests; test++)
    {
        int rows, cols;
        cin >> rows >> cols;
        string str;
        cin >> str;
        bool *isGoodCol = new bool[cols];
        for (int i = 0; i < cols; i++)
            isGoodCol[i] = false;
        int goodCols = 0;
        int *goodRowCt = new int[cols];
        for (int i = 0; i < cols; i++)
            goodRowCt[i] = 0;
        int topRowSmarts = 0;
        for (int i = 0; i < rows * cols; i++)
        {
            topRowSmarts += str[i] - '0';
            if (i >= cols)
                topRowSmarts -= str[i - cols] - '0';
            if (str[i] == '1' && !isGoodCol[i % cols])
                goodCols += (isGoodCol[i % cols] = true);
            if (topRowSmarts)
                goodRowCt[i % cols]++;
            cout << (goodCols + goodRowCt[i % cols]) << ' ';
        }
        cout << endl;
        delete[] isGoodCol;
        delete[] goodRowCt;
    }
    return 0;
}