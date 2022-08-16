// Official: Correct
#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    int tests, n;
    cin >> tests;
    for (int test = 0; test < tests; test++)
    {
        cin >> n;
        int *arr = new int[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        vector<int> options;
        int cost = 0;
        for (int i = 0; i < n; i++)
        {
            bool works = false;
            for (int j = 0; j < options.size(); j++)
                if (options[j] == arr[i])
                    works = true;
                else
                    options[j] ^= arr[i];
            options.push_back(arr[i]);
            if (works || arr[i] == 0)
                options.clear();
            else
                cost++;
        }
        cout << cost << endl;
    }
    return 0;
}