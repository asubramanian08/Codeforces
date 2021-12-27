// Official: Correct
#include <iostream>
using namespace std;

int main(void)
{
    int tests, numSongs;
    cin >> tests;
    for (int test = 0; test < tests; test++)
    {
        cin >> numSongs;
        int *rating = new int[numSongs];
        int *songAtRating = new int[numSongs];
        for (int i = 0; i < numSongs; i++)
        {
            cin >> rating[i];
            rating[i]--;
            songAtRating[rating[i]] = i;
        }
        string likes;
        cin >> likes;
        int totalDislikes = 0;
        for (int i = 0; i < numSongs; i++)
            if (likes[i] == '0')
                totalDislikes++;
        int *newRating = new int[numSongs];
        int likeCt = 0, dislikeCt = 0;
        for (int i = 0; i < numSongs; i++)
            newRating[songAtRating[i]] = likes[songAtRating[i]] == '0' ? (++dislikeCt) : ((++likeCt) + totalDislikes);
        for (int i = 0; i < numSongs; i++)
            cout << newRating[i] << ' ';
        cout << endl;
    }
    return 0;
}